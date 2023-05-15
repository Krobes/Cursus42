/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:24 by rbonilla          #+#    #+#             */
/*   Updated: 2023/05/15 12:55:31 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_text(int pid, char byte)
{
	int	bit_c;

	bit_c = 0;
	while (bit_c < 8)
	{
		if ((byte & (1 << bit_c)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit_c++;
	}
}

void	ft_transmit_data_in_bits(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("El mensaje ha sido enviado correctamente.");
}

int	main(int argc, char **argv)
{
	int					c;
	int					pid;
	struct sigaction	sign;

	c = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sign.sa_handler = &ft_transmit_data_in_bits;
		sigaction(SIGUSR1, &sign, NULL);
		while (argv[2][c] != '\0')
		{			
			ft_send_text(pid, argv[2][c]);
			c++;
		}
		ft_send_text(pid, argv[2][c]);
	}
	else
	{
		ft_printf("FORMATO ERRÓNEO\nPrueba así: ./client \"PID\" \"mensaje\"");
	}
	return (0);
}
