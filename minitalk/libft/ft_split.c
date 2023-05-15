/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:35 by rbonilla          #+#    #+#             */
/*   Updated: 2023/05/08 12:02:45 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_countword(char *str)
{
	int	indice;
	int	countword;

	indice = 0;
	countword = 0;
	while (str[indice])
	{
		while (str[indice] && (str[indice] == 9
				|| str[indice] == 10 || str[indice] == 32))
			indice++;
		if (str[indice] > 32 && str[indice] < 127)
			countword++;
		while (str[indice] > 32 && str[indice] < 127)
			indice++;
	}
	return (countword);
}

void	ft_separate_words(char *str, char **str_split)
{
	int	indice;
	int	indice2;
	int	indice3;

	indice = 0;
	indice2 = 2;
	indice3 = 0;
	while (str[indice])
	{
		while (str[indice] == 9 || str[indice] == 10 || str[indice] == 32)
			indice++;
		while (str[indice] > 32 && str[indice] < 127)
		{
			str_split[indice2][indice3] = str[indice];
			indice3++;
			indice++;
		}
		if (indice3 > 0)
			str_split[indice2][indice3] = 0;
		indice2++;
		indice3 = 0;
	}
}

void	ft_memory(char *str, char **str_split)
{
	int	indice;
	int	indice2;
	int	countword;

	indice = 0;
	indice2 = 0;
	countword = 0;
	while (str[indice])
	{
		while (str[indice] == 9 || str[indice] == 10 || str[indice] == 32)
				indice++;
		while (str[indice] && str[indice] > 32 && str[indice] < 127)
		{
			countword++;
			indice++;
		}
		if (countword > 0)
		{
			str_split[indice2] = malloc((countword + 1) * sizeof(char));
			countword = 0;
			indice2++;
		}
	}
}

char	**ft_split(char *str)
{
	char	**str_split;
	int		i;

	i = ft_countword(str);
	str_split = malloc((i + 1) * sizeof(char *));
	if (!str_split)
		return (0);
	str_split[i] = 0;
	ft_memory(str, str_split);
	ft_separate_words(str, str_split);
	return (str_split);
}
