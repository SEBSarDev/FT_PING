/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:28:16 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 20:07:07 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if ((!dest && src) || (!src && dest))
		*(temp_dest) = *temp_src;
	if (dest > src)
	{
		while (n-- > 0 && temp_src)
			*(temp_dest + n) = *(temp_src + n);
	}
	else
	{
		while (n > 0 && temp_src)
		{
			*temp_dest = *temp_src;
			temp_dest++;
			temp_src++;
			n--;
		}
	}
	return (dest);
}
