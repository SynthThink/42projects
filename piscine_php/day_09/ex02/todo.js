var content = [];

function create_cookie(name, content)
{
	document.cookie= name + "=" + content + ";" + "expires=Thu, 18 Dec 2025 12:00:00 UTC;";
}
function ft_create_div(message)
{
	var parent_list = document.getElementById('ft_list');
	var new_div = document.createElement('div');
	new_div.style.height = '80px';
	new_div.style.width = '200px';
	new_div.style.border = '1px solid black';
	new_div.style.marginTop = '10px';
	new_div.style.marginBottom = '10px';
	new_div.style.paddingLeft = '10px';
	new_div.style.background = 'black';
	new_div.style.color = 'white';
	var text = document.createTextNode(message);
	new_div.appendChild(text);
	new_div.setAttribute("onclick", "ft_delete(this)");
	parent_list.insertBefore(new_div, parent_list.firstChild);
	content.push(message);
	var json_content = JSON.stringify(content);
	create_cookie("divs", json_content);
}

function read_cookie(name)
{
	var text = document.cookie;

	var content_cookie = text.split(';');
	for(var i in content_cookie)
	{
		if (content_cookie[i].substring(0,4) == "divs")
		{

			var content = content_cookie[i].substring(5);
			content = JSON.parse(content);
			for(var c in content)
				ft_create_div(content[c]);
		}
	}
}
read_cookie("divs");

function ft_new (){
	var message = window.prompt();
	if (message != "" && message != null)
		ft_create_div(message);
}
function ft_delete (id){
	if (window.confirm("Do you really want to delete this note?"))
	{
		var search = id.firstChild;
		search = search['data'];
		var index = content.indexOf(search);
		if (index != -1)
		{
			content.splice(index, 1 );
			var json_content = JSON.stringify(content);
			create_cookie("divs", json_content);
		}
		id.parentNode.removeChild(id);
	}
}
