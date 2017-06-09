# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 15:07:40 by plamusse          #+#    #+#              #
#    Updated: 2017/06/09 17:15:04 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = testf

SRC = main.c ft_printf.c parser.c parsing_tools.c converter.c conv_tools.c \
	  stocker_cs.c indent_string.c indent_char.c helpers.c

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc -Wall -Werror -Wextra

INCLUDE = -I./libft/includes

all: $(NAME)

$(NAME):
	$(CC) $(INCLUDE) -c $(SRC)
	gcc -o $(NAME) -g $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

