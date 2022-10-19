/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:41:30 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/19 11:47:42 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstring(char *s);
int	ft_hexadecimal(__UINTPTR_TYPE__ a);
int	ft_signed_decimal(int i);
int	ft_unsigned_decimal(unsigned int i);
int	ft_low_or_upper_hex(unsigned int a, char c);

#endif
