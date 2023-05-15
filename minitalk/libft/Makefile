# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:27:51 by rbonilla          #+#    #+#              #
#    Updated: 2023/03/22 11:05:24 by rbonilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_isalpha.c\
		 ft_isdigit.c\
		 ft_isalnum.c\
		 ft_isascii.c\
		 ft_isprint.c\
		 ft_strlen.c\
		 ft_memset.c\
		 ft_bzero.c\
		 ft_memcpy.c\
		 ft_memmove.c\
		 ft_strlcpy.c\
		 ft_strlcat.c\
		 ft_toupper.c\
		 ft_tolower.c\
		 ft_strchr.c\
		 ft_strrchr.c\
		 ft_strncmp.c\
		 ft_memchr.c\
		 ft_memcmp.c\
		 ft_strnstr.c\
		 ft_atoi.c\
		 ft_calloc.c\
		 ft_strdup.c\
		 ft_substr.c\
		 ft_strjoin.c\
		 ft_strtrim.c\
		 ft_split.c\
		 ft_itoa.c\
		 ft_strmapi.c\
		 ft_striteri.c\
		 ft_putchar_fd.c\
		 ft_putstr_fd.c\
		 ft_putendl_fd.c\
		 ft_putnbr_fd.c


CBONUS = ft_lstnew_bonus.c\
		 ft_lstadd_front_bonus.c\
		 ft_lstsize_bonus.c\
		 ft_lstlast_bonus.c\
		 ft_lstadd_back_bonus.c\
		 ft_lstdelone_bonus.c\
		 ft_lstclear_bonus.c\
		 ft_lstiter_bonus.c\
		 ft_lstmap_bonus.c
	
CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libft.a
OBONUS = $(CBONUS:.c=.o)
OFILES = $(CFILES:.c=.o)
HEADER_FILE = libft.h

RM = rm -f

all: $(NAME)

$(NAME): $(OFILES) $(HEADER_FILE)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

bonus: $(OFILES) $(OBONUS)
	$(ARCHIVER) $(NAME) $(OFILES) $(OBONUS)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY : all clean fclean re

