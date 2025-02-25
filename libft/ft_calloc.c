/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:21:51 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 19:52:12 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*tab;

	if (nbr == 0 || size == 0)
	{
		nbr = 1;
		size = 1;
	}
	tab = malloc(size * nbr);
	if (!tab)
		return (NULL);
	if (tab)
		ft_bzero(tab, nbr * size);
	return (tab);
}
