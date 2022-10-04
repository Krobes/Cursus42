/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:10:48 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/04 13:46:32 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst)
	{
		if (*lst == NULL)
		*lst = new;
		else
		{		
			aux = ft_lstlast(*(lst));
			aux -> next = new;
		}
	}
}
