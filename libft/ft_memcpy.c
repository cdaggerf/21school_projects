/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:23 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 18:43:20 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *a, const void *c, unsigned int b)
{
	unsigned char	*d;
	unsigned char	*g;
	unsigned int	j;

	j = 0;
	if (!a && !c)
		return (0);
	d = (unsigned char *)a;
	g = (unsigned char *)c;
	while (j < b)
	{
		d[j] = g[j];
		j++;
	}
	return (d);
}
