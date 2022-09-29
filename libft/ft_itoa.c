/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:32 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/29 14:35:54 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ndigits(int	aux);

char	*ft_itoa(int n)
{
	char	*s;
	int		pos;
	int		dig;
	int		aux;
	
	aux = n;
	dig = 0;
	if (n == 0)
	{
		s = malloc(1);
		s[0] = '0';
		return (s);
	}
	if (n < 0)
	{
	s = malloc((ft_ndigits(n) + 2) * sizeof(char));
	s[0] = '-';
	}
	else
	s = malloc((ft_ndigits(n) + 1) * sizeof(char));
	if (!s)
		return (0);
	pos = ft_strlen(s) - 1;
	while (pos >= 0)
	{
		dig = aux % 10;
		aux = aux / 10;
		if (dig < 0)
			dig = dig * -1;
		s[pos] = dig + '0';
		pos--;
		if (n < 0 && s[1] != '\0' )
			pos = -1;
	}
	s[ft_strlen(s)] = 0;
	return (s);
}

static int	ft_ndigits(int	aux)
{
	int n_dig;

	n_dig = 0;
	while (aux != 0)
	{
		aux = aux / 10;
		n_dig++;
	}
	return (n_dig);
}


