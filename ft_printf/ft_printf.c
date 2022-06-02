/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:56:52 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/13 18:32:30 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(t_flags *flags, va_list arg)
{
	int	l;

	l = 0;
	if (flags->type == 'd' || flags->type == 'i')
		l = print_id(va_arg(arg, int), flags);
	if (flags->type == 'u')
		l = print_u(va_arg(arg, unsigned int), flags);
	if (flags->type == 'c')
		l = print_c(va_arg(arg, int), flags);
	if (flags->type == 's')
		l = print_str(va_arg(arg, char *), flags);
	if (flags->type == 'p')
		l = print_p(va_arg(arg, unsigned long), flags);
	if (flags->type == 'x')
		l = print_x(va_arg(arg, unsigned int), flags);
	if (flags->type == 'X')
		l = print_xxx(va_arg(arg, unsigned int), flags);
	if (flags->type == '%')
		l = print_str("%", flags);
	return (l);
}

int	ft_pars_flags(const char *format, int *i, t_flags *flags)
{
	*i = ft_min(format, i, flags);
	*i = ft_wid(format, i, flags);
	*i = ft_precis(format, i, flags);
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p'
		|| format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
		flags->type = format[(*i)++];
	return (*i);
}

int	ft_pars_start(const char *format, va_list arg)
{
	int		i;
	int		l;
	t_flags	flags;

	l = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			flags = ft_start_flags();
			i = ft_pars_flags(format, &i, &flags);
			l = l + ft_print(&flags, arg);
		}
		else if (format[i])
		{
			l = l + ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		l;

	l = 0;
	va_start(arg, format);
	l = l + ft_pars_start(format, arg);
	va_end(arg);
	return (l);
}
printf ("аоммгмгмгмгмг")
