/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:45:52 by rbonilla          #+#    #+#             */
/*   Updated: 2023/05/15 12:53:12 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *uap)
{
	static unsigned char	byte;
	static int				bit_c;

	(void)uap;
	if (signal == SIGUSR1)
		byte = byte | (1 << bit_c);
	bit_c++;
	if (bit_c == 8)
	{
		if (byte == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", byte);
		byte = 0;
		bit_c = 0;
	}
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = &handle_signal;
	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	sigaddset(&sign.sa_mask, SIGUSR1);
	sigaddset(&sign.sa_mask, SIGUSR2);
	ft_printf("Bienvenido a minitalk\nPID del proceso: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
		pause();
	}
	return (0);
}
