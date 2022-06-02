/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:50:19 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/30 17:58:51 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static void	free_error(char **result, int len)
{
	len--;
	result--;
	while (len >= 0)
	{
		free(*result);
		if (len != 0)
			result--;
		len--;
	}
	free(result);
}

static int	get_size(char const *s, char c)
{
	int	size;

	size = 0;
	if (ft_strlen(s) == 1)
		size = 0;
	s++;
	while (*(s - 1))
	{
		if (*(s - 1) != c && (*s == c || *s == 0))
			size++;
		s++;
	}
	return (size);
}

static int	get_len(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static char	**ft_checkit(char **result, const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		len = get_len(s, c);
		*result = malloc(len + 1);
		if (*result == 0)
		{
			free_error(result, i);
			return (0);
		}
		i++;
		ft_strlcpy(*result, s, len + 1);
		s += len;
		result++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		sz;
	char	**result;

	if (s == 0)
		return (0);
	sz = get_size(s, c);
	result = malloc((sz + 1) * sizeof (char *));
	if (result == 0)
		return (0);
	result = ft_checkit(result, s, c);
	if (result == 0)
		return (0);
	*result = 0;
	result -= sz;
	return (result);
}
