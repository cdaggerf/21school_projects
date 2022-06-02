/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:11:53 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 22:02:02 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_wid(int wid, int zero)
{
	int	l_ch;

	l_ch = 0;
	while (wid > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		wid--;
		l_ch++;
	}
	return (l_ch);
}

int	print_c(char c, t_flags *flags)
{
	int	l_ch;

	l_ch = 0;
	if (flags->min == 1)
		ft_putchar_fd(c, 1);
	if (flags->zero == 1)
		l_ch = ft_print_wid(flags->wid - 1, 1);
	else
		l_ch = ft_print_wid(flags->wid - 1, 0);
	if (flags->min == 0)
		ft_putchar_fd(c, 1);
	return (l_ch + 1);
}
