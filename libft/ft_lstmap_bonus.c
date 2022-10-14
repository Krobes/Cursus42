/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:19:26 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/06 12:55:43 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*final;

	if (!lst | !f)
		return (0);
	final = ft_lstnew((*f)(lst -> content));
	while (lst -> next)
	{
		lst = lst -> next;
		aux = ft_lstnew((*f)(lst -> content));
		if (!aux)
		{
			ft_lstclear(&final, del);
			return (0);
		}
		ft_lstadd_back(&final, aux);
	}
	return (final);
}
