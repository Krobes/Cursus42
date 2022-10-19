/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:01:23 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/19 11:49:01 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnbr(unsigned int i);
static int		ft_len(unsigned int i);

int	ft_unsigned_decimal(unsigned int i)
{
	unsigned int	len;

	len = 0;
	len = ft_len(i);
	ft_putnbr(i);
	return (len);
}

static void	ft_putnbr(unsigned int i)
{
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i % 10 + '0');
}

static int	ft_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i > 9)
	{
		i = i / 10;
		len++;
	}
	len++;
	return (len);
}
