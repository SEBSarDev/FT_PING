/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:45:55 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 22:08:48 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	*ft_copy(void *dest, const void *src, size_t n)
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

void	ft_fill_ptr(char *ptr, const char *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == 0)
		return ((char *)s);
	if (start >= ft_strlen_s(s))
	{
		ptr = (char *)malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr = ft_copy(ptr, "", 1);
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (len <= 0 || !s)
	{
		ptr[len] = 0;
		return (ptr);
	}
	ft_fill_ptr(ptr, s, len, start);
	return (ptr);
}
