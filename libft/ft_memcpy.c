/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:59:23 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:05:54 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		if (temp_dest == temp_src)
			return (NULL);
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
		n--;
	}
	return (dest);
}
