/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:40:38 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 21:15:31 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	if (!dest || !src)
		return (0);
	len = ft_strlen_s(src);
	i = 0;
	if (n <= 0)
		return (len);
	while (i + 1 < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i])
		dest[i] = '\0';
	return (len);
}
