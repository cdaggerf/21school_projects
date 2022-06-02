/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:28 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 16:45:29 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int n)
{
	unsigned int	i;
	char			*a;
	char			*b;

	a = (char *)src;
	b = (char *)dst;
	i = 0;
	if (a == b || n == 0)
		return (dst);
	if (b > a)
		while (n-- > 0)
			b[n] = a[n];
	else
	{
		while (i < n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (dst);
}
