/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:59:34 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/28 10:45:02 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if ((!needle[0]))
		return ((char *)haystack);
	while (haystack[i])
	{
		a = 0;
		while (haystack[i + a] == needle[a] && (i + a < len))
		{
			if (!needle[a + 1])
				return ((char *)&haystack[i]);
			a++;
		}
		i++;
	}
	return (0);
}
