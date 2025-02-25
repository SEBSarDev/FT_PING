/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:23:22 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 16:24:16 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_len_nb(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_free_tab(char *tab)
{
	free(tab);
	return (NULL);
}

void	set_null(char **ptr)
{
	(*ptr)[0] = '(';
	(*ptr)[1] = 'n';
	(*ptr)[2] = 'u';
	(*ptr)[3] = 'l';
	(*ptr)[4] = 'l';
	(*ptr)[5] = ')';
	(*ptr)[6] = '\0';
}

char	*ft_dup2(char *s)
{
	char	*ptr;
	int		len;
	int		i;

	i = -1;
	if (s == NULL)
	{
		ptr = (char *)malloc(sizeof(char) * 7);
		if (!ptr)
			return (NULL);
		set_null(&ptr);
		return (ptr);
	}
	len = ft_len(s);
	ptr = (char *)malloc(sizeof(char) * (ft_len(s) + 1));
	if (!ptr)
		return (NULL);
	while (++i < ft_len(s))
		ptr[i] = s[i];
	ptr[len] = '\0';
	return (ptr);
}

int	ft_next(const char *str)
{
	int	count;

	count = 1;
	while (str[count] && ft_is_in("cspdiuxX%", str[count]) != 1)
		count++;
	count++;
	return (count);
}
