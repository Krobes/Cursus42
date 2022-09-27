/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:41:53 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/23 14:28:07 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t n;
	size_t	j;

	i = 0;
	j = 0;
	n = 0;	
	if(dstsize == 0)
		return (ft_strlen(src));
	if(dstsize < ft_strlen(dst))
		n = dstsize + ft_strlen(src);
	else
		n = ft_strlen(src) + ft_strlen(dst);
	while(dst[i])
		i++;
	while(i < dstsize - 1 && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (n);
}
