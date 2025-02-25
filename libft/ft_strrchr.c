/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:07:12 by ssar              #+#    #+#             */
/*   Updated: 2020/11/21 18:31:34 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;
	size_t	i;

	i = 0;
	ptr_s = NULL;
	if (!c)
	{
		while (s[i])
			i++;
		ptr_s = &(((char *)s)[i]);
		return (ptr_s);
	}
	while (s[i])
	{
		if (s[i] == c)
			ptr_s = &(((char *)s)[i]);
		i++;
	}
	return (ptr_s);
}
