/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:01:23 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/19 11:48:21 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnbr(int i);
static int		ft_len(int i);

int	ft_signed_decimal(int i)
{
	int	len;

	len = 0;
	len = ft_len(i);
	if (i == -2147483648)
	{
		write (1, "-2", 2);
		i = i + 2000000000;
		i = i * -1;
	}
	if (i < 0)
	{
		write (1, "-", 1);
		i = i * -1;
		ft_putnbr(i);
	}
	else
	{
		ft_putnbr(i);
	}
	return (len);
}

static void	ft_putnbr(int i)
{
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i % 10 + '0');
}

static int	ft_len(int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
		return (11);
	else if (i < 0)
	{
		len++;
		i = i * -1;
	}
	while (i > 9)
	{
		i = i / 10;
		len++;
	}
	len++;
	return (len);
}
