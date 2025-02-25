/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:51:26 by ssar              #+#    #+#             */
/*   Updated: 2021/02/02 22:09:06 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inbase(const char c)
{
	int		i;
	char	*base;

	base = "0123456789";
	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	int				n;
	unsigned int	nbr;

	i = ft_space(str);
	nbr = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_inbase(str[i]) != -1)
	{
		nbr = nbr * 10 + ft_inbase(str[i]);
		i++;
	}
	if (neg < 0)
		return (n = nbr * neg);
	else
		return (nbr);
}
