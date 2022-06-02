/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:29:19 by cdaggerf          #+#    #+#             */
/*   Updated: 2022/04/01 20:58:00 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	i = 0;
	if (!s)
		return (0);
	// if (c == '\0')
	// 	return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *l_string, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!l_string)
	{
		l_string = (char *)malloc(1 * sizeof(char));
		l_string[0] = '\0';
	}
	if (!l_string || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(l_string) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	// if (l_string)
		while (l_string[++i] != '\0')
			str[i] = l_string[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(l_string) + ft_strlen(buff)] = '\0';
	free(l_string);
	return (str);
}

char	*ft_get_line(char *l_string)
{
	int		i;
	char	*str;

	i = 0;
	if (!l_string[i])
		return (NULL);
	while (l_string[i] && l_string[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (l_string[i] && l_string[i] != '\n')
	{
		str[i] = l_string[i];
		i++;
	}
	if (l_string[i] == '\n')
	{
		str[i] = l_string[i];
		i++;
	}
	str[i] = '\0';
	// printf ("KEK %d\ncumBoL %c\n", i, str[++i]);
	return (str);
}

char	*ft_new_left_str(char *l_string)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (l_string[i] && l_string[i] != '\n')
		i++;
	if (!l_string[i])
	{
		free(l_string);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(l_string) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (l_string[i])
		str[j++] = l_string[i++];
	str[j] = '\0';
	free(l_string);
	return (str);
}
