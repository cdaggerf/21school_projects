/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:45:48 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/11 16:45:49 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *a, int b)
{
	while (*a != (char) b)
	{
		if (!*a++)
		{
			return (NULL);
		}
	}
	return ((char *)a);
}
