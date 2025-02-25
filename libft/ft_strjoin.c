/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:15:15 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 10:13:27 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_fill(char *ptr, const char *s1, const char *s2)
{
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	while (s1[u])
		ptr[i++] = s1[u++];
	u = 0;
	while (s2[u])
		ptr[i++] = s2[u++];
	ptr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	if (s1 == 0)
		return ((char *)s2);
	if (s2 == 0)
		return ((char *)s1);
	ptr = (char *)malloc((ft_stl(s1) + ft_stl(s2)) + 1);
	if (!ptr)
		return (NULL);
	len = ft_stl(s1) + ft_stl(s2);
	if (len <= 0)
	{
		ptr[len] = 0;
		return (ptr);
	}
	ft_fill(ptr, s1, s2);
	return (ptr);
}
