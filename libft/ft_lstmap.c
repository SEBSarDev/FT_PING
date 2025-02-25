/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:03:02 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:08:57 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*one;

	if (!lst)
		return (0);
	new = 0;
	one = 0;
	while (lst)
	{
		one = ft_lstnew((*f)(lst->content));
		if (!one)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, one);
		lst = lst->next;
	}
	return (new);
}
