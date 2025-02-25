/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:32:11 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 16:43:45 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_tab(long long n, char *base_to, char **tab, int len)
{
	while (n >= (long long)ft_len(base_to))
	{
		ft_fill_tab(n / ft_len(base_to), base_to, tab, len - 1);
		n = n % ft_len(base_to);
	}
	(*tab)[len] = base_to[n];
}

int	ft_size_of_conv(long long n, char *base_to)
{
	int	u;

	u = 1;
	if (n >= (long long)ft_len(base_to))
	{
		return (1 + ft_size_of_conv(n / ft_len(base_to), base_to));
	}
	return (u);
}

void	ft_init_exception(int excep, char *tab, int *len)
{
	if (excep == -1)
	{
		*len = *len - 2;
		tab[0] = '-';
		tab[*len + 1] = '\0';
	}
	else if (excep == 2)
	{
		*len = *len - 3;
		tab[0] = '0';
		tab[1] = 'x';
		tab[*len + 2] = '\0';
		*len = *len + 1;
	}
	else
	{
		*len = *len - 1;
		tab[*len] = '\0';
		*len = *len - 1;
	}
}

char	*ft_itoa_base(long long n, char *base_to, int excep)
{
	int		len;
	char	*tab;

	len = ft_size_of_conv(n, base_to);
	if (excep == -1)
		len += 2;
	else if (excep == 2)
		len += 3;
	else
		len++;
	tab = (char *)malloc(sizeof(char) * (len));
	if (!tab)
		return (NULL);
	ft_init_exception(excep, tab, &len);
	ft_fill_tab(n, base_to, &tab, len);
	return (tab);
}
