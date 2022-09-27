/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:38:44 by rbonilla          #+#    #+#             */
/*   Updated: 2022/09/21 09:38:48 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	a;

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		a = 1;
	else
		a = 0;
	return (a);
}
