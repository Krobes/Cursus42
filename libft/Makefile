# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:27:51 by rbonilla          #+#    #+#              #
#    Updated: 2022/09/23 11:09:15 by rbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = *.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libft.a
OFILES = $(CFILES:.c=.o)
HEADER_FILE = libft.h

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

