/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:50:00 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/23 11:46:09 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	aux;

	aux = 0;
	i = 0;
	while (src[i])
		i++;
	if(destsize != 0)
	{
		while (src[aux] != 0 && aux < destsize - 1)
		{
			dst[aux] = src[aux];
			aux++;
		}
		dst[aux] = 0;
	}
	return (i);
}
