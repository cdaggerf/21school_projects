/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:55 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 21:42:53 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (size > 0 && (i < (size - 1)))
		{
			dest[i] = src[i];
			j++;
		}
		i++;
	}
	if (size == 0)
		return (i);
	dest[j] = '\0';
	return (i);
}
