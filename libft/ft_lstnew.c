/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:23:14 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/04 11:42:02 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (!var)
		return (0);
	var ->content = content;
	var ->next = 0;
	return (var);
}
