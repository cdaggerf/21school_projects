/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:44 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 16:45:45 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, unsigned int b)
{
	unsigned char	*d;

	d = a;
	while (b > 0)
	{
		d[b - 1] = (unsigned char) c;
		b--;
	}
	return (d);
}
