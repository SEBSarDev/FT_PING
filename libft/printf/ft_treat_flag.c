/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:42:16 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 14:47:40 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dup_and_free(char *p)
{
	int		i;
	char	*tab;
	int		len;

	len = ft_len(p);
	i = 0;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (p[i])
	{
		tab[i] = p[i];
		i++;
	}
	tab[i] = '\0';
	free(p);
	return (tab);
}

char	*ft_treat_precision(char *tab, char c, int precision)
{
	char	*new_tab;

	if (c == 's')
	{
		if (precision >= 0 && ft_len(tab) > precision)
		{
			new_tab = ft_treat_prec_s(tab, precision);
			if (!new_tab)
				return (NULL);
		}
		else
			return (tab);
	}
	else
	{
		if (precision > 0 && ft_len_nb(tab) < precision)
		{
			new_tab = ft_treat_prec_nb(tab, precision, 0);
			if (!new_tab)
				return (NULL);
		}
		else
			return (tab);
	}
	return (new_tab);
}

char	*ft_larg(char *tab, t_flag flag)
{
	char	*new_tab;

	if (ft_len(tab) < flag.larg_min)
	{
		new_tab = ft_treat_larg_min(tab, flag.larg_min);
		if (!new_tab)
			return (NULL);
		if (flag.to_left != 0)
			ft_treat_to_left(&new_tab);
		if (flag.pad_zero != 0 && flag.precision < 0 && flag.to_left == 0)
			ft_treat_pad_zero(&new_tab);
	}
	else
		return (tab);
	return (new_tab);
}

char	*flag_precision(char **tab, t_flag flag, char c)
{
	if (flag.isprecision)
	{
		*tab = ft_treat_precision(*tab, c, flag.precision);
		if (!(*tab))
			return (ft_free_tab(*tab));
	}
	if (flag.larg_min)
	{
		*tab = ft_larg(*tab, flag);
		if (!(*tab))
			return (ft_free_tab(*tab));
	}
	return (*tab);
}

char	*ft_treat_flag(char *p, t_flag flag, char c)
{
	char	*tab;

	if (flag.isprecision == 0 && flag.larg_min == 0
		&& flag.to_left == 0 && flag.pad_zero == 0)
		return (p);
	if (flag.precision == 0 && ft_cmp(p, "0") == 0)
	{
		free(p);
		tab = ft_strdup("");
		if (!tab)
			return (NULL);
	}
	else
	{
		tab = ft_dup_and_free(p);
		if (!tab)
			return (NULL);
	}
	flag_precision(&tab, flag, c);
	return (tab);
}
