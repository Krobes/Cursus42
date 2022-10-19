# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:27:51 by rbonilla          #+#    #+#              #
#    Updated: 2022/10/19 11:22:48 by rbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_putchar.c\
		 ft_putstring.c\
		 ft_printf.c\
		 ft_hexadecimal.c\
		 ft_signed_decimal.c\
		 ft_unsigned_decimal.c\
		 ft_lowcase_hexadecimal.c			
CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libftprintf.a

OFILES = $(CFILES:.c=.o)
HEADER_FILE = ft_printf.h

RM = rm -f

all: $(NAME)

$(NAME): $(OFILES) $(HEADER_FILE)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY : clean fclean re

