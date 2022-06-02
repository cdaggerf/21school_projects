/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:16:50 by cdaggerf          #+#    #+#             */
/*   Updated: 2022/04/01 19:42:24 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_left_str(int fd, char *l_string);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *l_string, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *l_string);
char	*ft_new_left_str(char *l_string);

#endif