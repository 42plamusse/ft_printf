# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 15:07:40 by plamusse          #+#    #+#              #
#    Updated: 2017/06/07 21:11:04 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = testf

SRC = main.c ft_printf.c 

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc -Wall -Werror -Wextra

INCLUDE = -I./libft/includes

all: $(NAME)

$(NAME):
	@(cd ./libft/ && $(MAKE))
	$(CC) $(INCLUDE) -c $(SRC)
	gcc -o $(NAME) -g $(OBJ) -L libft/ -lft
	@(cd ./libft/ && $(MAKE) fclean)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

