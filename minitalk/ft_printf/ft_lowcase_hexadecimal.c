/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowcase_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:26:15 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/19 11:28:24 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int a);

static void	ft_hex_putchar(unsigned int a, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (a >= 16)
	{
		ft_hex_putchar(a / 16, c);
		ft_hex_putchar(a % 16, c);
	}
	else
	{
		ft_putchar(hex[a]);
	}
}

int	ft_low_or_upper_hex(unsigned int a, char c)
{
	int	len;

	len = 0;
	if (!a)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	ft_hex_putchar(a, c);
	len += ft_hex_len(a);
	return (len);
}

static int	ft_hex_len(unsigned int a)
{
	int	len;

	len = 0;
	while (a > 0)
	{
		a = a / 16;
		len++;
	}
	return (len);
}
