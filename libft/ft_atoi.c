/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:11:39 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 15:58:56 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atoi2(unsigned long num, int neg)
{
	if (num > 9223372036854775807)
	{
		if (neg == 1)
			return (0);
		else
			return (-1);
	}
	if (neg == 1)
		return (-num);
	else
		return (num);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	num;
	unsigned long	j;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == '\n') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		num *= 10;
		num += (int)str[i] - '0';
		i++;
	}
	j = ft_atoi2(num, neg);
	return ((int) j);
}
