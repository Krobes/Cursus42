/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:13:33 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/28 10:42:18 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	result;

	a = 0;
	result = 0;
	while ((s1[a] != 0 || s2[a] != 0) && a < n)
	{
		if (s1[a] == s2[a])
			a++;
		else
		{
			result = ((unsigned char *)s1)[a] - ((unsigned char *)s2)[a];
			return (result);
		}
	}
	return (0);
}
