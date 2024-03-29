/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:44:42 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 18:38:56 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *a, unsigned int b)
{
	unsigned char	*d;

	d = a;
	while (b > 0)
	{
		((char *)d)[b - 1] = 0;
		b--;
	}
}
