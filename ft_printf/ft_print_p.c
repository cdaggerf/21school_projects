/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:11:59 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/19 04:37:31 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_po(unsigned long num)
{
	int	l;

	l = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		l++;
		num = num / 16;
	}
	return (l);
}

static int	pri_ox(void)
{
	ft_putstr_fd("0x", 1);
	return (2);
}

int	pre_point(char *str, int l, t_flags *flags, unsigned long nb)
{
	int	l_po;

	l_po = l;
	if ((flags->precis > l && flags->precis < flags->wid) \
	&& flags->min == 0)
	{
		l += ft_print_wid(flags->wid - flags->precis - 2, 0);
		l += pri_ox();
		l += ft_print_wid(flags->precis - l_po, 1);
		l += 2;
		ft_putstr_fd(str, 1);
	}
	if (flags->precis > l)
	{
		l += pri_ox();
		l += ft_print_wid(flags->precis - l + 2, 1);
		if (nb != 0)
			ft_putstr_fd(str, 1);
		if (flags->wid - l > 0)
			l += ft_print_wid(flags->wid - l, 0);
	}
	return (l);
}

int	wid_point(char *str, int l, t_flags *flags)
{
	if (l < flags->wid)
	{
		if ((flags->wid - l > 2) && flags->min == 0)
		{
			l += ft_print_wid(flags->wid - l - 2, 0);
			l += pri_ox();
			if (flags->precis != 0)
				ft_putstr_fd(str, 1);
		}
		else
		{
			l += pri_ox();
			if (flags->precis != 0)
				ft_putstr_fd(str, 1);
			if (flags->wid - l > 0)
				l += ft_print_wid(flags->wid - l, 0);
		}
	}
	else
	{
		l += pri_ox();
		ft_putstr_fd(str, 1);
	}
	return (l);
}

int	print_p(unsigned long nb, t_flags *flags)
{
	char	*str;
	int		l;
	int		l_po;

	l = 1;
	if (flags->precis == -1 && nb == 0)
		str = ft_strdup("0");
	else
	{
		if (nb != 0)
			l_po = ft_len_po(nb);
		else
			l_po = 0;
		l = l_po;
		str = ft_itoa_x(nb);
	}
	l = print_point(str, l, flags, nb);
	free(str);
	return (l);
}
