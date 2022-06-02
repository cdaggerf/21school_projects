/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:36:14 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/19 01:15:33 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_start_flags(void)
{
	t_flags	flags;

	flags.min = 0;
	flags.zero = 0;
	flags.wid = 0;
	flags.precis = -1;
	flags.type = 0;
	return (flags);
}

int	ft_min(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format [*i] == '0')
	{
		if (format[*i] == '-')
			flags->min = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		(*i)++;
	}
	if (flags->min == 1)
		flags->zero = 0;
	return (*i);
}

int	ft_wid(const char *format, int *i, t_flags *flags)
{
	while (ft_isdigit(format[*i]))
	{
		flags->wid = (flags->wid * 10) + (format[*i] - '0');
		(*i)++;
	}
	return (*i);
}

int	ft_precis_two(const char *format, int *i, t_flags *flags)
{
	int	num;
	int	f;

	num = 0;
	f = 0;
	if (format[*i] == '-')
	{
		flags->min = 1;
		flags->precis = 0;
		f = 1;
		(*i)++;
	}
	while (ft_isdigit(format[*i]))
	{
		num = (num * 10) + (format[*i] - '0');
		(*i)++;
	}
	if (f == 0)
		flags->precis = num;
	else if (f == 1)
		flags->wid = num;
	return (*i);
}

int	ft_precis(const char *format, int *i, t_flags *flags)
{
	int	num;

	num = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		*i = ft_precis_two(format, i, flags);
	}
	return (*i);
}
