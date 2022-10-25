/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:44:22 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/25 14:14:21 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		count;
	size_t		j;
	char		*s3;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s3)
		return (0);
	count = 0;
	while (i > count)
	{
		s3[count] = s1[count];
		count++;
	}
	count = 0;
	while (j  >= count)
	{
		s3[i + count] = s2[count];
		count++;
	}
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		if ((char)c == 0 && s[i + 1] == 0)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (0);
	ft_bzero(s, count * size);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
		((unsigned char *)s)[i] = '\0';
			i++;
		}
	}
}
