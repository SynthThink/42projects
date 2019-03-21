import torch
import torchvision
import torchvision.transforms as transforms
import torchvision.models as models
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np
import torch.nn.functional as F
import os
import copy
from PIL import Image

print(torch.cuda.device_count())
# os.environ['TORCH_MODEL_ZOO'] = '/sgoinfre/goinfre/Perso/malluin'
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
imsize = 512 if torch.cuda.is_available() else 512

loader = transforms.Compose(
    [transforms.Resize((imsize, imsize)), transforms.ToTensor()])
unloader = transforms.ToPILImage()

def image_loader(image_name):
	image_load = Image.open(image_name)
	old_size = image_load.size
	image_load = loader(image_load).unsqueeze(0)
	new_size = (image_load.size()[2], image_load.size()[3])
	print("Rescaling from {}x{} to {}x{}".format(old_size[0],
		old_size[1], new_size[0], new_size[1]))
	return image_load.to(device, torch.float)

def show_image(tensor, i, row = 1, col = 2):
	tensor = tensor.squeeze(0)
	image = unloader(tensor)
	plt.subplot(row, col, i)
	plt.imshow(image)

style_img_path = "vangogh.jpg"
content_img_path = "nono.jpg"
style_img = image_loader(style_img_path)
content_img = image_loader(content_img_path)
old_size = reversed(Image.open(content_img_path).size)
old_size = tuple(old_size)

print(style_img.size(), content_img.size())
assert style_img.size() == content_img.size()

load_resize = transforms.Compose([transforms.Resize(old_size), transforms.ToTensor()])
def scale_up_save(tensor, i):
	resized = tensor.squeeze(0)
	resized = unloader(resized.cpu())
	# resized.save('test1.jpg')
	resized = load_resize(resized)
	resized = resized.squeeze(0)
	resized = unloader(resized)
	resized.save('results_NST/output' + str(i) +'.jpg')
	print('saving results_NST/output' + str(i) +'.jpg...')

# show_image(style_img.cpu(), 1)
# show_image(content_img.cpu(), 2)
# plt.show()

class ContentLoss(nn.Module):

    def __init__(self, target,):
        super(ContentLoss, self).__init__()
        # we 'detach' the target content from the tree used
        # to dynamically compute the gradient: this is a stated value,
        # not a variable. Otherwise the forward method of the criterion
        # will throw an error.
        self.target = target.detach()

    def forward(self, input):
        self.loss = F.mse_loss(input, self.target)
        return input

def gram_matrix(input):
	a, b, c, d = input.size()
	# a=batch size(=1)
	# b=number of feature maps
	# (c,d)=dimensions of a f. map (N=c*d)
	features = input.view(a * b, c * d)
	G = torch.mm(features, features.t())
	# compute the gram product
	# we 'normalize' the values of the gram matrix
	# by dividing by the number of element in each feature maps.
	return G.div(a * b * c * d)


class StyleLoss(nn.Module):

    def __init__(self, target,):
        super(StyleLoss, self).__init__()
        # we 'detach' the target content from the tree used
        # to dynamically compute the gradient: this is a stated value,
        # not a variable. Otherwise the forward method of the criterion
        # will throw an error.
        self.target = target.detach()

    def forward(self, input):
        self.loss = F.mse_loss(gram_matrix(input), gram_matrix(self.target))
        return input

cnn = models.vgg19(pretrained = True).features.to(device).eval()
cnn_normalization_mean = torch.tensor([0.485, 0.456, 0.406]).to(device)
cnn_normalization_std = torch.tensor([0.229, 0.224, 0.225]).to(device)

class Normalization(nn.Module):
	def __init__(self, mean, std):
		super(Normalization, self).__init__()
		self.mean = torch.tensor(mean).view(-1, 1, 1)
		self.std = torch.tensor(std).view(-1, 1, 1)

	def forward(self, input):
		return ((input - self.mean) / self.std)

content_layers_default = ['conv_4']
style_layers_default = ['conv_1', 'conv_2', 'conv_3', 'conv_4', 'conv_5']
# style_layers_default = ['conv_1', 'conv_2', 'conv_3', 'conv_4', 'conv_5', 'conv_6', 'conv_7', 'conv_8', 'conv_9', 'conv_10', 'conv_11', 'conv_12', 'conv_13', 'conv_14', 'conv_15', 'conv_16']
# style_layers_default = ['conv_1', 'conv_2', 'conv_3', 'conv_4', 'conv_5']

def get_style_model_and_losses(cnn, normalization_mean, normalization_std,
                               style_img, content_img, content_layers=content_layers_default,
                               style_layers=style_layers_default):
	cnn = copy.deepcopy(cnn)
	normalization = Normalization(normalization_mean, normalization_std).to(device)
	content_losses = []
	style_losses = []
	# assuming that cnn is a nn.Sequential, so we make a new nn.Sequential
	# to put in modules that are supposed to be activated sequentially
	model = nn.Sequential(normalization)

	i = 0  # increment every time we see a conv
	for layer in cnn.children():
		if isinstance(layer, nn.Conv2d):
			i += 1
			name = 'conv_{}'.format(i)
			# print(name)
		elif isinstance(layer, nn.ReLU):
			name = 'relu_{}'.format(i)
			# The in-place version doesn't play very nicely with the ContentLoss
			# and StyleLoss we insert below. So we replace with out-of-place
			# ones here.
			layer = nn.ReLU(inplace=False)
		elif isinstance(layer, nn.MaxPool2d):
			name = 'pool_{}'.format(i)
		elif isinstance(layer, nn.BatchNorm2d):
			name = 'bn_{}'.format(i)
		else:
			raise RuntimeError('Unrecognized layer: {}'.format(layer.__class__.__name__))
		model.add_module(name, layer)
		if name in content_layers:
            # add content loss:
			target = model(content_img).detach()
			content_loss = ContentLoss(target)
			model.add_module("content_loss_{}".format(i), content_loss)
			content_losses.append(content_loss)

		if name in style_layers:
			# add style loss:
			target_feature = model(style_img).detach()
			style_loss = StyleLoss(target_feature)
			model.add_module("style_loss_{}".format(i), style_loss)
			style_losses.append(style_loss)

    # now we trim off the layers after the last content and style losses
	for i in range(len(model) - 1, -1, -1):
		if isinstance(model[i], ContentLoss) or isinstance(model[i], StyleLoss):
			break
	model = model[:(i + 1)]
	return model, style_losses, content_losses

input_img = content_img.clone()
# input_img = torch.randn(content_img.data.size(), device=device)

def get_input_optimizer(input_img):
	optimizer = optim.LBFGS([input_img.requires_grad_()])
	return optimizer

def run_style_transfer(cnn, normalization_mean, normalization_std,
						content_img, style_img, input_img, num_steps=5000,
						style_weight=1000000, content_weight=1):
	print('Building the style transfer model..')
	model, style_losses, content_losses = get_style_model_and_losses(cnn,
	normalization_mean, normalization_std, style_img, content_img)
	optimizer = get_input_optimizer(input_img)
	print('Optimizing..')
	run = [0]
	save_images = [ ]
	while run[0] <= num_steps:
		def closure():
			# correct the values of updated input image
			input_img.data.clamp_(0, 1)

			optimizer.zero_grad()
			model(input_img)
			style_score = 0
			content_score = 0

			for sl in style_losses:
				style_score += sl.loss
			for cl in content_losses:
				content_score += cl.loss

			style_score *= style_weight
			content_score *= content_weight

			loss = style_score + content_score
			loss.backward()

			run[0] += 1
			if run[0] % 5 == 4:
				print("run {}:".format(run))
				print('Style Loss : {:4f} Content Loss: {:4f}'.format(
				style_score.item(), content_score.item()))
				print()
				if run[0] % 50 == 49:
					tmp = copy.deepcopy(input_img.data.clamp_(0, 1))
					save_images.append(tmp)
					scale_up_save(tmp, run[0] / 5)
			return style_score + content_score
		optimizer.step(closure)

	input_img.data.clamp_(0, 1)
	return save_images, input_img


save_images, output = run_style_transfer(cnn, cnn_normalization_mean, cnn_normalization_std,
                            content_img, style_img, input_img)

i = 1
plt.figure(figsize=(20,20))
# for image in save_images:
# 	# show_image(image, i, 2, 5)
# 	# scale_up_save(image, i)
# 	plt.subplot(5, 10, i)
# 	plt.imshow(resized)
# 	i += 1
show_image(output.detach().cpu(), 1)

plt.show()
