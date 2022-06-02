/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:54:50 by cdaggerf          #+#    #+#             */
/*   Updated: 2022/04/02 11:57:51 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_read_left_str(int fd, char *l_string)
{
	char	*buff;
	int		rd_byt, k;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_byt = 1;
	while (!ft_strchr(l_string, '\n') && rd_byt != 0)
	{
		rd_byt = read(fd, buff, BUFFER_SIZE);
		// printf("%d\n", rd_byt);
		if (rd_byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_byt] = '\0';
		l_string = ft_strjoin(l_string, buff);
		// k = ft_strlen(l_string);
		// printf("%d\n", k);
	}
	free(buff);
	return (l_string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*l_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	l_string = ft_read_left_str(fd, l_string);
	// printf("LOL %s", l_string);
	if (!l_string)
		return (NULL);
	line = ft_get_line(l_string);
	// printf("KEK %s", line);
	l_string = ft_new_left_str(l_string);
	return (line);
}

int main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
	// printf("%d\n", fd1);
	// fd1 = open("tests/test.txt", O_RDONLY);
//	fd2 = open("tests/test2.txt", O_RDONLY);
//	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		i++;
	}
	return (0);
}
	
