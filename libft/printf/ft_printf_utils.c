/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:42:27 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 11:05:43 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_in(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_show_c_is_zero(char *str, t_flag *stock, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stock->to_left == 1)
	{
		write(1, "\0", 1);
		count++;
	}
	while (i < len - 1)
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	if (stock->to_left == 0)
	{
		write(1, "\0", 1);
		count++;
	}
	return (count);
}

int	ft_show(char *str, t_flag *stock)
{
	int	i;
	int	len;
	int	count;

	count = 0;
	i = 0;
	len = ft_len(str);
	if (stock->c_is_zero == 1)
		count = ft_show_c_is_zero(str, stock, len);
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
