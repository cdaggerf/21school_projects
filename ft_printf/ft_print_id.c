/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:18:28 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 21:53:31 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	neg_precis_pos(t_flags *flags, int l_id, int l, char *str)
{
	if (flags->wid > l_id && flags->min == 0)
	{
		if (!flags->zero)
			l = l + ft_print_wid(flags->wid - l_id, 0);
		else if (flags->wid > l_id)
			l = l + ft_print_wid(flags->wid - l_id, 1);
	}
	ft_putstr_fd(str, 1);
	if (flags->wid > l_id && flags->min == 1)
		l = l + ft_print_wid(flags->wid - l_id, 0);
	return (l);
}

static int	pos_precis_pol(t_flags *flags, int l_id, int l, char *str)
{
	if (flags->wid > flags->precis && flags->min == 0)
	{
		if (flags->precis > l_id)
			l = l + ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l_id)
			l = l + ft_print_wid(flags->wid - l_id, 0);
	}
	if (flags->precis > l_id)
		l = l + ft_print_wid(flags->precis - l_id, 1);
	ft_putstr_fd(str, 1);
	if (flags->wid > flags->precis && flags->min == 1)
	{
		if (flags->precis > l_id)
			l = l + ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l_id)
			l = l + ft_print_wid(flags->wid - l_id, 0);
	}
	return (l);
}

int	print_pos_id(int num, t_flags *flags)
{
	char	*str;
	int		l;
	int		l_id;

	l = 0;
	if (num == 0 && flags->precis == 0)
	{
		l = ft_print_wid(flags->wid, 0);
		return (l);
	}
	str = ft_itoa(num);
	l_id = ft_strlen(str);
	if (flags->precis == -1)
		l = neg_precis_pos(flags, l_id, l, str);
	else if (flags->precis >= 0)
		l = pos_precis_pol(flags, l_id, l, str);
	free(str);
	return (l + l_id);
}

int	print_id(int num, t_flags *flags)
{
	int	l;

	l = 0;
	if (num >= 0)
		l = print_pos_id(num, flags);
	else
		l = print_neg_id(num, flags);
	return (l);
}
