/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:43:08 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 19:58:57 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp_lst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_lst;
	}
	lst = 0;
}
