/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:26:15 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/19 10:41:30 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(__UINTPTR_TYPE__ a);

void	ft_hex_putchar(__UINTPTR_TYPE__ a)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (a >= 16)
	{
		ft_hex_putchar(a / 16);
		ft_hex_putchar(a % 16);
	}
	else
	{
		ft_putchar(hex[a]);
	}
}

int	ft_hexadecimal(__UINTPTR_TYPE__ a)
{
	int	len;

	len = 2;
	write (1, "0x", len);
	if (!a)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	ft_hex_putchar(a);
	len += ft_hex_len(a);
	return (len);
}

int	ft_hex_len(__UINTPTR_TYPE__ a)
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
