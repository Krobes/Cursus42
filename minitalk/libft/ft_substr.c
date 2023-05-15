/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:14:39 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/29 10:11:12 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
	{
		s2 = malloc(1);
		s2[0] = '\0';
		return (s2);
	}
	s2 = malloc((len + 1) * sizeof(char));
	if (!s || !s2)
		return (0);
	while (len > 0 && s[start])
	{
		s2[i] = s[start];
		len--;
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
