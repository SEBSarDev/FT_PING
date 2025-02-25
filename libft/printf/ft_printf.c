/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:46:59 by ssar              #+#    #+#             */
/*   Updated: 2024/05/21 14:57:39 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_treat(const char *str, va_list cpy, int i)
{
	char	*p;
	int		len;
	t_flag	flags;

	p = NULL;
	flags = ft_init_flag(str, cpy, ft_default_flag());
	while (ft_is_in("cspdiuxX%", str[i]) == 0)
		i++;
	if (str[i] == '%')
		ft_char_to_str('%', &p, &flags);
	if (str[i] == 's')
		p = ft_dup2(va_arg(cpy, char *));
	if (str[i] == 'c')
		ft_char_to_str((unsigned char)va_arg(cpy, int), &p, &flags);
	if (ft_is_in("pdiuxX", str[i]) == 1)
		ft_conv_nbr(cpy, str, &p, i);
	if (p == NULL)
		return (-1);
	p = ft_treat_flag(p, flags, str[i]);
	if (!p)
		return (-1);
	len = ft_show(p, &flags);
	free(p);
	return (len);
}

int	check_format(const char *str)
{
	int	i;

	i = 1;
	while (ft_is_in("*.-0123456789", str[i]) == 1)
		i++;
	if (ft_is_in("cspdiuxX%", str[i]) == 0)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	l;

	l = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			i++;
			l++;
		}
		if (str[i] == '%')
		{
			if (check_format(&str[i]) == 0)
				return (l);
			l += ft_treat(&str[i], ap, 1);
			i += ft_next(&str[i]);
		}
	}
	va_end(ap);
	return (l);
}
