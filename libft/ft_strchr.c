/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:26:51 by ssar              #+#    #+#             */
/*   Updated: 2020/11/21 18:27:39 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*ptr_s;

	i = 0;
	if (c == '\0' && s)
	{
		while (s[i])
			i++;
		ptr_s = &(((char *)s)[i]);
		return (ptr_s);
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			ptr_s = &(((char *)s)[i]);
			return (ptr_s);
		}
		i++;
	}
	return (NULL);
}
