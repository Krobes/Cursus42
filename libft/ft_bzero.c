/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:16:07 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/23 11:07:30 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;
	int		i;

	b = (char *)s;
	i = 0;
	while (n > 0)
	{
		b[i] = 0;
		n--;
		i++;
	}
}
