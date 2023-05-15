/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:51 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/10 13:01:24 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c);
static char	*ft_lenwords(char *s, int aux, char c);
static int	ft_memory(char *s, int aux, char c);
static int	ft_position(char *s, int pos, char c);

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		words;
	int		x;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	words = ft_countwords((char *)s, c);
	final = (char **)malloc((sizeof (char *) * (words + 1)));
	if (!final)
		return (0);
	x = 0;
	while (x < words)
	{
		final[x] = ft_lenwords((char *)s, pos, c);
		i = ft_position((char *)s, pos, c);
		pos = i;
		x++;
	}
	final[x] = 0;
	return (final);
}

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	*ft_lenwords(char *s, int aux, char c)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	while (s[aux] && s[aux] == c)
		aux++;
	j = ft_memory(s, aux, c);
	final = (char *)malloc(sizeof(char) * j + 1);
	if (!final)
		return (0);
	while (s[aux] != c && s[aux])
	{
		final[i] = s[aux];
		i++;
		aux++;
	}
	final[i] = 0;
	return (final);
}

static int	ft_memory(char *s, int aux, char c)
{
	int	i;

	i = 0;
	while (s[aux] != c && s[aux])
	{
		i++;
		aux++;
	}
	return (i);
}

static int	ft_position(char *s, int pos, char c)
{
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
		pos++;
	return (pos);
}
