/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:25:09 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/27 10:02:33 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(void)
{
	char	dst[15] = "Hola";
	const char	*src = "adios";
	size_t	len = 3;

	printf("%s", memmove(dst, src, len));	
}*/


void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst)
		a++;
	if (n == 0)
		return(dst);
	else if (n <= a)
	{
		while (n > 0 || src)
		{
			((unsigned char	*)dst)[b] = ((unsigned char *)src)[b];
			n--;
			b++;
		}
	}	
	return(dst);
}
