/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:12:04 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 22:20:37 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pos_prec_unsign(t_flags *flags, \
int l_unsign, int l, char *unsign)
{
	if (flags->wid > flags->precis && flags->min == 0)
	{
		if (flags->precis > l_unsign)
			l += ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l_unsign)
			l += ft_print_wid(flags->wid - l_unsign, 0);
	}
	if (flags->precis > l_unsign)
		l += ft_print_wid(flags->precis - l_unsign, 1);
	ft_putstr_fd(unsign, 1);
	if (flags->wid > flags->precis && flags->min)
	{
		if (flags->precis > l_unsign)
			l += ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l)
			l += ft_print_wid(flags->wid - ft_strlen(unsign), 0);
	}
	return (l);
}

static int	ft_neg_prec_unsign(t_flags *flags, \
int l_unsign, int l, char *unsign)
{
	if (flags->wid > l_unsign && flags->min == 0)
	{
		if (flags->zero == 1)
			l += ft_print_wid(flags->wid - l_unsign, 1);
		else
			l += ft_print_wid(flags->wid - l_unsign, 0);
	}
	ft_putstr_fd(unsign, 1);
	if (flags->wid > l_unsign && flags->min == 1)
		l += ft_print_wid(flags->wid - l_unsign, 0);
	return (l);
}

int	print_u(unsigned int num, t_flags *flags)
{
	int		l;
	int		l_unsign;
	char	*unsign;

	l = 0;
	if (flags->precis == 0 && num == 0)
	{
		l += ft_print_wid(flags->wid, 0);
		return (l);
	}
	unsign = ft_itoa_two(num);
	l_unsign = ft_strlen(unsign);
	if (flags->precis == -1)
		l += ft_neg_prec_unsign(flags, l_unsign, l, unsign);
	if (flags->precis >= 0)
		l += ft_pos_prec_unsign(flags, l_unsign, l, unsign);
	free(unsign);
	return (l + l_unsign);
}
