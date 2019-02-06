# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2018/12/06 13:38:31 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_NAME = main.c \
					 ft_image.c \
					 ft_key_hook.c \
					 ft_mouse_hook.c \
					 ft_pixel_utils.c \
					 ft_expose_hook.c
					 
SRC_PATH = src
OBJ_PATH = obj
INCLUDES = ./includes/
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./libft/ -I $(INCLUDES)
LIBFLAGS = -L ./libft/ -lft
MLXFLAGS = -I ./minilibx_macos/ ./minilibx_macos/libmlx.a
FRMWORK = -framework OpenGL -framework AppKit


OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LIBFLAGS) $(MLXFLAGS) $(FRMWORK)  $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $(CPPFLAGS) -ggdb -o $@ -c $<

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re
