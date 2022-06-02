/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:12:06 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 21:53:48 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_x(unsigned long num)
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

char	*ft_itoa_x(unsigned long num)
{
	int		l;
	char	*str;

	l = ft_len_x(num);
	str = malloc(l + 1);
	if (!str)
		return (NULL);
	str[l--] = '\0';
	str[0] = '0';
	while (l >= 0)
	{
		if (num % 16 >= 10)
			str[l--] = (num % 16) + 87;
		else
			str[l--] = (num % 16) + 48;
		num /= 16;
	}
	return (str);
}

static int	ft_pos_prec_x(t_flags *flags, int l_x, int l, char *str)
{
	if (flags->wid > flags->precis && flags->min == 0)
	{
		if (flags->precis > l_x)
			l += ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l_x)
			l += ft_print_wid(flags->wid - l_x, 0);
	}
	if (flags->precis > l_x)
		l += ft_print_wid(flags->precis - l_x, 1);
	ft_putstr_fd(str, 1);
	if (flags->wid > flags->precis && flags->min)
	{
		if (flags->precis > l_x)
			l += ft_print_wid(flags->wid - flags->precis, 0);
		else if (flags->wid > l_x)
			l += ft_print_wid(flags->wid - ft_strlen(str), 0);
	}
	return (l);
}

static int	ft_neg_prec_x(t_flags *flags, int l_x, int l, char *str)
{
	if (flags->wid > l_x && flags->min == 0)
	{
		if (flags->zero == 1)
			l += ft_print_wid(flags->wid - l_x, 1);
		else
			l += ft_print_wid(flags->wid - l_x, 0);
	}
	ft_putstr_fd(str, 1);
	if (flags->wid > l_x && flags->min == 1)
		l += ft_print_wid(flags->wid - l_x, 0);
	return (l);
}

int	print_x(unsigned int num, t_flags *flags)
{
	unsigned long	nbr;
	int				l;
	int				l_x;
	char			*str;

	l = 0;
	if (flags->precis == 0 && num == 0)
	{
		l += ft_print_wid(flags->wid, 0);
		return (l);
	}
	nbr = (unsigned long)num;
	l_x = ft_len_x(nbr);
	str = ft_itoa_x(nbr);
	if (flags->precis == -1)
		l += ft_neg_prec_x(flags, l_x, l, str);
	if (flags->precis >= 0)
		l += ft_pos_prec_x(flags, l_x, l, str);
	free(str);
	return (l + l_x);
}
