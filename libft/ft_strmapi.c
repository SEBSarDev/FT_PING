/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:15:31 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 21:19:53 by ssar             ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	if (s == 0)
		return ((char *)s);
	len = ft_strlen_s(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
