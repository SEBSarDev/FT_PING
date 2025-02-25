/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:16:47 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 21:14:36 by ssar             ###   ########.fr       */
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

static size_t	ft_strlen_d(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	j = 0;
	len_src = ft_strlen_s(src);
	len_dest = ft_strlen_d(dest, n);
	i = len_dest;
	while (i + 1 < n && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dest[i] = '\0';
	if (n > len_dest)
		return (len_dest + len_src);
	return (n + len_src);
}
