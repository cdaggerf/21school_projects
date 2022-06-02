/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:51 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 16:45:52 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*a;
	unsigned int	i;

	a = (char *)malloc(sizeof(*a) * (ft_strlen(s1) + 1));
	if (a == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			a[i] = s1[i];
			i++;
		}
		a[i] = '\0';
		return (a);
	}
}
