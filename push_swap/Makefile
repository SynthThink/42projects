# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/02/05 16:16:12 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

SRC_NAME =	ft_checker.c \
			ft_parse.c \
			ft_lst.c \
			ft_operations.c \
			ft_error.c \
			ft_process.c \
			ft_visu_image.c \
			ft_visu_utils.c \
			ft_visu_events.c \
			ft_visu.c

SRC2_NAME = ft_push_swap.c \
			ft_parse.c \
			ft_error.c \
			ft_lst.c \
			ft_operations.c \
			ft_bubble_sort.c \
			ft_selection_sort.c \
			ft_quick_sort.c \
			ft_swap_intra.c \
			ft_utils_quick_sort.c \
			ft_utils.c

SRC_PATH = src_checker
OBJ_PATH = obj_checker

SRC2_PATH = src_push
OBJ2_PATH = obj_push

INCLUDES = ./includes/
CC = gcc
CCFLAGS = -Wall -Wextra -ggdb #-Werror
CPPFLAGS = -I ./libftprintf/includes -I $(INCLUDES) -I ./libftprintf/libft/includes
LIBFLAGS = -L ./libftprintf/ -lftprintf
MLXFLAGS = -I ./minilibx_macos/ ./minilibx_macos/libmlx.a
FRMWORK = -framework OpenGL -framework AppKit

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2_NAME = $(SRC2_NAME:.c=.o)
SRC2 = $(addprefix $(SRC2_PATH)/,$(SRC2_NAME))
OBJ2 = $(addprefix $(OBJ2_PATH)/,$(OBJ2_NAME))

all: $(NAME) $(NAME2)


$(NAME): $(OBJ)
	@make -C libftprintf/
	@make -C minilibx_macos
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LIBFLAGS) $(MLXFLAGS) $(FRMWORK) $^ -o $@

$(NAME2): $(OBJ2)
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LIBFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ2_PATH)/%.o: $(SRC2_PATH)/%.c
	@mkdir $(OBJ2_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C libftprintf/
	@make clean -C minilibx_macos
	rm -f $(OBJ) $(OBJ2)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(OBJ2_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libftprintf/
	@rm -f $(NAME) $(NAME2)

re: fclean
	$(MAKE)

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re
