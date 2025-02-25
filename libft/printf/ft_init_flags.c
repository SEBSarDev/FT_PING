/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:27:42 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 11:14:57 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_init_point(const char *str, va_list cpy, int *i, t_flag *stock)
{
	int	nb;

	stock->isprecision = 1;
	if (str[*i + 1] == '*')
	{
		nb = va_arg(cpy, int);
		(*i)++;
		return (nb);
	}
	else
	{
		nb = ft_atoi(&str[*i + 1]);
		while (ft_is_in("0123456789", str[(*i) + 1]) == 1)
			(*i)++;
		return (nb);
	}
}

int	ft_init_num(const char *str, int *i, int j)
{
	int	nb;

	if (str[*i - 1] == '.')
	{
		while (ft_is_in("0123456789", str[(*i) + 1]) == 1)
			(*i)++;
		return (j);
	}
	else
	{
		nb = ft_atoi(&str[*i]);
		while (ft_is_in("0123456789", str[(*i) + 1]) == 1)
			(*i)++;
		return (nb);
	}
}

char	ft_which_conv(const char *str)
{
	int	i;

	i = 1;
	while (ft_is_in("cspdiuxX%", str[i]) == 0)
		i++;
	return (str[i]);
}

t_flag	ft_default_flag(void)
{
	t_flag	stock;

	stock.pad_zero = 0;
	stock.larg_min = 0;
	stock.precision = -1;
	stock.to_left = 0;
	stock.isprecision = 0;
	stock.c_is_zero = 0;
	return (stock);
}

t_flag	ft_init_flag(const char *str, va_list cpy, t_flag stock)
{
	int		i;
	char	c;

	i = 1;
	c = ft_which_conv(str);
	while (ft_is_in("cspdiuxX%", str[i]) == 0)
	{
		if (str[i] == '0' && ft_is_in("diuxX%", c) == 1)
			stock.pad_zero = 1;
		else if (str[i] == '-')
			stock.to_left = 1;
		else if (str[i] == '*')
			stock.larg_min = va_arg(cpy, int);
		else if (str[i] == '.' && ft_is_in("sdiuxX", c) == 1)
			stock.precision = ft_init_point(str, cpy, &i, &stock);
		else if (ft_is_in("123456789", str[i]) == 1)
			stock.larg_min = ft_init_num(str, &i, stock.larg_min);
		if (stock.larg_min < 0)
		{
			stock.larg_min = stock.larg_min * (-1);
			stock.to_left = 1;
		}
		i++;
	}
	return (stock);
}
