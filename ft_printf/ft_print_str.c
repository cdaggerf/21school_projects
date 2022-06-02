/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:12:02 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 21:58:03 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int num)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < num)
		write(1, &str[i++], 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	print_str(char *str, t_flags *flags)
{
	int	l;
	int	l_str;

	if (!str)
		str = "(null)";
	l = 0;
	l_str = ft_strlen(str);
	if (flags->precis >= 0)
	{
		if (l_str > flags->precis)
			l_str = flags->precis;
	}
	if (flags->min)
		ft_putnstr(str, l_str);
	if (flags->wid > l_str)
	{
		if (flags->zero)
			l = ft_print_wid((flags->wid - l_str), 1);
		else
			l = ft_print_wid(flags->wid - l_str, 0);
	}
	if (flags->min == 0)
		ft_putnstr(str, l_str);
	return (l + l_str);
}
