CFLAGS = gcc -Wall -Werror -Wextra
PRINTF = ft_printf/
LIBFT = libft/

all: 	 
	@make -C ${PRINTF} 
	@make -C ${LIBFT} 
	@${CFLAGS} libft/libft.a ft_printf/libftprintf.a server.c -o server
	@${CFLAGS} libft/libft.a ft_printf/libftprintf.a client.c -o client
	@echo "Minitalk is ready"

bonus: all

clean:
	@make fclean -s -C ${PRINTF}
	@make fclean -s -C ${LIBFT}
	@echo "Compiled objects have been removed"

fclean: clean
	@rm -f server client
	@echo "Executables have been removed"

re: fclean all

.PHONY: all bonus clean fclean re
