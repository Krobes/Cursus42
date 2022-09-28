/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:15:02 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/28 10:32:44 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		a;

	a = 0;
	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (n > 0)
	{
		if (((unsigned const char *)s1)[i] == ((unsigned const char *)s2)[i])
		{
			i++;
			n--;
		}
		else
		{
			a = ((unsigned const char *)s1)[i] - ((unsigned const char *)s2)[i];
			return (a);
		}
	}
	return (0);
}
