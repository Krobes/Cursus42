/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:09:09 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/28 10:59:46 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vartype(va_list *args, char c);

int	ft_printf(char const *str, ...)
{
	int		total;
	int		i;
	va_list	args;

	total = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total += ft_vartype(&args, str[i + 1]);
			i++;
		}
		else
			total += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (total);
}

int	ft_vartype(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(*args, int));
	else if (c == 's')
		i = ft_putstring(va_arg(*args, char *));
	else if (c == 'p')
		i = ft_hexadecimal(va_arg(*args, __UINTPTR_TYPE__));
	else if (c == 'd')
		i = ft_signed_decimal(va_arg(*args, int));
	else if (c == 'i')
		i = ft_signed_decimal(va_arg(*args, int));
	else if (c == 'u')
		i = ft_unsigned_decimal(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		i = ft_low_or_upper_hex(va_arg(*args, unsigned int), c);
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}
