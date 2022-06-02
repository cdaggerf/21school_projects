/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:14 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 23:04:28 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char		*lol;
	unsigned int		i;

	i = 0;
	lol = (unsigned char *)s;
	while (i < n)
	{
		if (lol[i] == (unsigned char)c)
			return ((void *)&lol[i]);
		i++;
	}
	return (NULL);
}
