/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:46:56 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 22:55:11 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dsize)
		i++;
	while (src[j] && (i + j + 1) < dsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
