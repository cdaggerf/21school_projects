/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:05 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/13 19:48:05 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *need, size_t l)
{
	size_t	i;
	size_t	j;

	if (*need == '\0' || need == NULL)
		return ((char *)hs);
	i = 0;
	while (hs[i] != '\0' && i < l)
	{
		j = 0;
		while (need[j] == hs[i + j] && (i + j) < l)
		{
			if (need[j + 1] == '\0')
				return ((char *)hs + i);
			j++;
		}
		i++;
	}
	return (0);
}
