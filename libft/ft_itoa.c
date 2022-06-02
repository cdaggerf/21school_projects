/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:34:02 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/14 14:46:55 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_plus(int n, int l)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (l + 1));
	if (s)
	{
		s[l] = '\0';
		l--;
		s[0] = '-';
		while (l >= 0)
		{
			s[l] = ((n % 10) + '0');
			n /= 10;
			l--;
		}
		return (s);
	}
	return (NULL);
}

static char	*ft_minus(int n, int l)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (l + 2));
	if (s)
	{
		l++;
		s[l] = '\0';
		l--;
		s[0] = '-';
		while (l > 0)
		{
			s[l] = ((n % 10) + '0');
			n /= 10;
			l--;
		}
		return (s);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		l;
	int		num;

	l = 0;
	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		l = 1;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	if (num >= 0)
		return (s = ft_plus(num, l));
	return (s = ft_minus((num * -1), l));
}
