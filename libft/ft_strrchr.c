/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:09 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 19:02:46 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*b;
	char			lol;

	b = (char *)s;
	lol = (char )c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (b[i] == lol)
			return (b + i);
		i--;
	}
	if (b[i] == lol)
		return (b);
	return (0);
}
