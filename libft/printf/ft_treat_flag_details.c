/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flag_details.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:54:57 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 11:15:38 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_treat_prec_s(char *tab, int precision)
{
	char	*new_tab;
	int		i;

	i = 0;
	new_tab = (char *)malloc(sizeof(char) * (precision + 1));
	if (!new_tab)
		return (NULL);
	while (i < precision)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = '\0';
	free(tab);
	return (new_tab);
}

char	*ft_treat_prec_nb(char *tab, int precision, int j)
{
	char	*new_tab;
	int		i;
	int		len;

	i = 0;
	len = precision - ft_len(tab);
	if (tab[0] == '-')
	{
		precision = precision + 1;
		len = precision - (ft_len(tab) - 1);
		j = 1;
	}
	new_tab = (char *)malloc(sizeof(char) * (precision + 1));
	if (!new_tab)
		return (NULL);
	new_tab[precision] = '\0';
	while (i < len)
		new_tab[i++] = '0';
	while (tab[j] != '\0')
		new_tab[i++] = tab[j++];
	if (tab[0] == '-')
		new_tab[0] = '-';
	free(tab);
	return (new_tab);
}

char	*ft_treat_larg_min(char *tab, int larg_min)
{
	char	*new_tab;
	int		len;
	int		i;

	i = larg_min - 1;
	len = ft_len(tab);
	new_tab = (char *)malloc(sizeof(char) * (larg_min + 1));
	if (!new_tab)
		return (NULL);
	new_tab[larg_min] = '\0';
	while (len > 0)
	{
		new_tab[i] = tab[len - 1];
		i--;
		len--;
	}
	while (i >= 0)
	{
		new_tab[i] = ' ';
		i--;
	}
	free(tab);
	return (new_tab);
}

void	ft_treat_to_left(char **tab)
{
	int	i;
	int	j;
	int	len;

	len = ft_len(*tab);
	j = 0;
	i = 0;
	while ((*tab)[i] == ' ')
		i++;
	while (i < len)
	{
		(*tab)[j] = (*tab)[i];
		i++;
		j++;
	}
	while (j < len)
	{
		(*tab)[j] = ' ';
		j++;
	}
}

void	ft_treat_pad_zero(char **tab)
{
	int	i;

	i = 0;
	while ((*tab)[i] == ' ')
	{
		(*tab)[i] = '0';
		i++;
	}
	if ((*tab)[i] == '-')
	{
		(*tab)[i] = '0';
		(*tab)[0] = '-';
	}
}
