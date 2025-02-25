/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:18:49 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:02:41 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		if (*temp_src == (unsigned char)c)
			return (temp_dest);
		temp_src++;
		n--;
	}
	return (NULL);
}
