/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:18 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 20:32:50 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while ((*(char *)s1 == *(char *)s2) && --n)
	{
		s1 = (char *)s1 + 1;
		s2 = (char *)s2 + 1;
	}
	if (*(char *)s1 != *(char *)s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
