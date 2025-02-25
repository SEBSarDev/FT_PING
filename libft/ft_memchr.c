/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:40:48 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:04:49 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;

	temp_s = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (n > 0)
	{
		if (*temp_s == temp_c)
			return (temp_s);
		temp_s++;
		n--;
	}
	return (NULL);
}
