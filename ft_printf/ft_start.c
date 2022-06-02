/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:11:50 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/18 22:23:32 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_l(unsigned int n)
{
	int	l;

	l = 0;
	if (n < 0)
		l++;
	if (n == 0)
		return (1);
	while (n)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa_two(unsigned int num)
{
	int		l;
	char	*str;

	l = ft_l(num);
	str = malloc(l + 1);
	if (!str)
		return (NULL);
	str[l--] = '\0';
	str[0] = '0';
	if (num < 0)
		str[0] = '-';
	while (l)
	{
		if (num < 0)
			str[l--] = -(num % 10) + '0';
		else
			str[l--] = (num % 10) + '0';
		num /= 10;
	}
	if (num > 0)
		str[l] = num + '0';
	return (str);
}

int	print_point(char *str, int l, t_flags *flags, unsigned long nb)
{
	if (flags->precis > l)
		l = pre_point(str, l, flags, nb);
	else if (flags->wid == 0)
	{
		ft_putstr_fd("0x", 1);
		l += 2;
		if (flags->precis != 0)
			ft_putstr_fd(str, 1);
	}
	else if (flags->wid)
		l = wid_point(str, l, flags);
	return (l);
}
