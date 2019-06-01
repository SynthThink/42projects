# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/01/29 18:18:58 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_NAME =	ft_ls.c \
			ft_lst.c \
			ft_lst2.c \
			ft_parse.c \
			ft_free.c \
			ft_readdir.c \
			ft_errors.c \
			ft_check.c \
			ft_print.c \
			ft_print_elem.c \
			ft_print_elem2.c \
			ft_print_col.c \
			ft_utils.c

SRC_PATH = src
OBJ_PATH = obj
INCLUDES = ./includes/
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./libftprintf/includes -I $(INCLUDES) -I ./libftprintf/libft/includes
LIBFLAGS = -L ./libftprintf/ -lftprintf

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libftprintf/
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LIBFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C libftprintf/
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libftprintf/
	@rm -f $(NAME)

re: fclean
	$(MAKE)

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re
