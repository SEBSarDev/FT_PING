/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:02:23 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:05:26 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while ((*temp_s1 == *temp_s2) && (--n > 0))
	{
		temp_s1++;
		temp_s2++;
	}
	return (*temp_s1 - *temp_s2);
}
