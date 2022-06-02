/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:12:43 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/11/07 16:12:23 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		*ft_calloc(unsigned int count, unsigned int size);
void		ft_bzero(void *a, unsigned int b);
void		*ft_memchr(const void *s, int c, unsigned int n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dst, const void *src, unsigned int n);
int			ft_isalpha(int a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isprint(int a);
int			ft_isalnum(int a);
void		*ft_memset(void *a, int c, unsigned int b);
void		*ft_memcpy(void *a, const void *c, unsigned int b);
size_t		ft_strlen(const char *s);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *a, int b);
int			ft_touper(int c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *hs, const char *need, size_t l);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(char const *s, size_t start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
int			get_next_line(int fd, char **line);
void		ft_putstr(char const *s);
void		ft_putchar(char c);

#endif