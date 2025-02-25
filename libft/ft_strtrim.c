/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:11:54 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 21:23:17 by ssar             ###   ########.fr       */
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

static int	ft_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	size_t	len;

	len = ft_strlen_s(s1);
	i = 0;
	while (ft_in_set(s1[i], set) == 1)
		i++;
	if (!s1[i])
		return (0);
	while (ft_in_set(s1[len - 1], set) == 1)
		len--;
	size = len - i;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_trim;
	size_t	t;
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len_trim = ft_count(s1, set);
	ptr = (char *)malloc(sizeof(char) * (len_trim + 1));
	if (!ptr)
		return (NULL);
	while (ft_in_set(s1[i], set) == 1)
		i++;
	if (!s1)
		return (ptr = 0);
	t = 0;
	while (t < len_trim && s1[i])
	{
		ptr[t] = s1[i];
		t++;
		i++;
	}
	ptr[t] = '\0';
	return (ptr);
}
