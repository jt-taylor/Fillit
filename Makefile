# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2018/11/19 10:19:20 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -I ./Libft/includes

SRC = list_functions.c \
	  main.c \
	  place_pieces.c \
	  point.c \
	  read.c \
	  solve.c \
	  square.c \
	  tetri_utility.c \
	  tetrimino.c \


.PHONY = all clean fclean re

all : $(NAME)

$(NAME) :
	make -C ./Libft
	gcc $(FLAGS) $(SRC) ./Libft/libft.a -o fillit

clean :
	make -C Libft clean

fclean : clean
	rm -rf $(NAME)
	make -C Libft fclean

re : fclean all
