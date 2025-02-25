/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:05:13 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 11:04:34 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_conv_nbr(va_list cpy, const char *str, char **p, int i)
{
	long long	nb;

	if (str[i] == 'p')
	{
		nb = (long long)va_arg(cpy, void *);
		*p = ft_itoa_base(nb, "0123456789abcdef", 2);
	}
	if (str[i] == 'd' || str[i] == 'i')
	{
		nb = va_arg(cpy, int);
		if (nb < 0)
			*p = ft_itoa_base((long long)nb * -1, "0123456789", -1);
		else
			*p = ft_itoa_base((long long)nb, "0123456789", 1);
	}
	if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
	{
		nb = (long long)va_arg(cpy, unsigned int);
		if (str[i] == 'u')
			*p = ft_itoa_base(nb, "0123456789", 1);
		if (str[i] == 'x')
			*p = ft_itoa_base(nb, "0123456789abcdef", 1);
		if (str[i] == 'X')
			*p = ft_itoa_base(nb, "0123456789ABCDEF", 1);
	}
}

void	ft_char_to_str(unsigned char c, char **p, t_flag *stock)
{
	if (c == 0)
		stock->c_is_zero = 1;
	*p = (char *)malloc(2);
	if (!(*p))
	{
		*p = NULL;
		return ;
	}
	(*p)[0] = c;
	(*p)[1] = '\0';
}
