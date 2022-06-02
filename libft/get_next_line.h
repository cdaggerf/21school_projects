/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:42:40 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/11/03 17:42:41 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ERROR "Error\n"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
int		ft_finishing(char *aux, char **line, int x, int i);
int		ft_analize(char *aux);
int		ft_strlena(const char *s);
char	*ft_strjoina(char *s1, char *s2);
#endif