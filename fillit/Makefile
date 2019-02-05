# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:11:39 by malluin           #+#    #+#              #
#    Updated: 2018/11/21 17:09:23 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c utils.c print.c checks.c

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./libft/includes/
OBJ = $(SRC.c=.o)
LDFLAGS = -Llibft
LDLIBS = -lft

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all, clean, fclean, re
