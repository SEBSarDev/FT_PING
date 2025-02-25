/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:43:18 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 21:21:51 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strcmp_s(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen_s(s1) == ft_strlen_s(s2))
	{
		while (s1[i] == s2[i] && s1[i])
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (-1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (ft_strcmp_s(to_find, "") == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		k = i;
		while (str[k] == to_find[j] && k < len)
		{
			k++;
			j++;
			if (!to_find[j])
				return (&((char *)str)[i]);
		}
		i++;
	}
	return (NULL);
}
