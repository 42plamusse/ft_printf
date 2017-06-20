# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/18 15:07:40 by plamusse          #+#    #+#              #
#    Updated: 2017/06/19 20:26:07 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c parser.c parsing_tools.c converter.c conv_tools.c \
	  stocker_cs.c indent_string.c indent_char.c helpers.c indent_tools.c \
	  stocker_signed.c indent_signed.c itoa.c stocker_oux.c stocker_unsigned.c \
	  indent_unsigned.c stocker_octal.c indent_octal.c stocker_hexa.c \
	  indent_hexa.c stocker_cap_hexa.c indent_cap_hexa.c


OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

cc:
	$(CC)  -c main.c $(SRC)
	$(CC)  -o testf main.o $(OBJ) 

cclean: fclean
	rm -f testf
