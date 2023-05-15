/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:52:32 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/13 13:16:00 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ndigits(long int aux);

char	*ft_itoa(int n)
{
	char	*s;
	int		pos;
	long	aux;
	int		len;

	aux = n;
	len = ft_ndigits(aux);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		aux = aux * -1;
		s[0] = '-';
	}
	pos = len - 1;
	if (aux == 0)
		s[0] = '0';
	while (aux > 0)
	{
		s[pos--] = (aux % 10) + '0';
		aux = aux / 10;
	}
	s[len] = '\0';
	return (s);
}

static int	ft_ndigits(long int aux)
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
