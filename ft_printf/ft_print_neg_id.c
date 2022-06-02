/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_neg_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:11:56 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 22:30:07 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	neg_prec_neg(t_flags *flags, int l_id, int l, char *str)
{
	if ((flags->wid > l_id + 1) && flags->min == 0)
	{
		if (!flags->zero && (flags->wid - l_id - 1) > 0)
		{
			l += ft_print_wid(flags->wid - l_id - 1, 0);
			ft_putchar_fd('-', 1);
		}
		else if ((flags->wid - l_id - 1) > 0)
		{
			ft_putchar_fd('-', 1);
			l += ft_print_wid(flags->wid - l_id - 1, 1);
		}
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_putstr_fd(str, 1);
		if (flags->wid > l_id && flags->min == 1
			&& (flags->wid - l_id - 1) > 0)
			l += ft_print_wid(flags->wid - l_id - 1, 0);
	}
	return (l + 1);
}

static int	neg_prec_pol(t_flags *flags, int l_id, int l, char *str)
{
	if (flags->wid > flags->precis && flags->min == 0)
	{
		if (flags->precis > l_id)
			l += ft_print_wid(flags->wid - flags->precis - 1, 0);
		else if (flags->wid - l_id - 1 > 0)
			l += ft_print_wid(flags->wid - l_id - 1, 0);
	}
	ft_putchar_fd('-', 1);
	if (flags->precis > l_id)
		l += ft_print_wid(flags->precis - l_id, 1);
	ft_putstr_fd(str, 1);
	if (flags->wid > flags->precis && flags->min == 1)
	{
		if (flags->precis > l_id)
			l += ft_print_wid(flags->wid - flags->precis - 1, 0);
		else if (flags->wid - l_id - 1 > 0)
			l += ft_print_wid(flags->wid - l_id - 1, 0);
	}
	return (l + 1);
}

int	print_neg_id(int n, t_flags *flags)
{
	char			*str;
	int				l_id;
	int				l;
	unsigned int	m;

	l = 0;
	m = (unsigned int) - n;
	str = ft_itoa_two(m);
	l_id = ft_strlen(str);
	if (flags->precis == -1)
		l = neg_prec_neg(flags, l_id, l, str);
	else if (flags->precis >= 0)
		l = neg_prec_pol(flags, l_id, l, str);
	free(str);
	return (l + l_id);
}
