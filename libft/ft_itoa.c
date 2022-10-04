/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:32 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/03 12:15:55 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ndigits(long aux);
static void	*ft_convert(char *s, int pos, int dig, long aux);

char	*ft_itoa(int n)
{
	char		*s;
	int			pos;
	int			dig;
	long		aux;

	dig = 0;
	aux = n;
	s = malloc((ft_ndigits(aux) + 1) * sizeof(char));
	if (!s)
		return (0);
	s[ft_ndigits(aux)] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (n < 0)
		s[0] = '-';
	pos = ft_ndigits(aux) - 1;
	ft_convert(s, pos, dig, aux);
	return (s);
}

static int	ft_ndigits(long aux)
{
	int	n_dig;
	int	dig;

	n_dig = 0;
	if (aux == 0)
		return (1);
	while (aux != 0)
	{
		dig = aux % 10;
		if (dig < 0)
		{
			aux = aux * -1;
			n_dig++;
		}
		n_dig++;
		aux = aux / 10;
	}
	return (n_dig);
}

static void	*ft_convert(char *s, int pos, int dig, long aux)
{
	while (pos >= 0 && s[pos] != '-')
	{
		dig = aux % 10;
		aux = aux / 10;
		if (dig < 0)
			dig = dig * -1;
		s[pos] = dig + '0';
		pos--;
	}
	return (s);
}
