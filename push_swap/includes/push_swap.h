/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:23:09 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/05 19:10:22 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_element
{
	int					value;
	char				*binar;
	struct s_element	*next;
}	t_element;

int			ft_isdigit(char *str);
void		ft_lstadd_back(t_element **list_shell, t_element *new);
t_element	*ft_lstnew(int value);
int			ft_strlen(const char *s);
void		sa(t_element **a, int n);
void		sb(t_element **b, int n);
void		ss(t_element **a, t_element **b);
void		pa(t_element **a, t_element **b);
void		pb(t_element **a, t_element **b);
void		ra(t_element **a, int n);
void		rb(t_element **b, int n);
void		rr(t_element **a, t_element **b);
void		rra(t_element **a, int n);
void		rrb(t_element **b, int n);
void		rrr(t_element **a, t_element **b);
void		ft_error(void);
int			ft_atoi(const char *str);
char		*to_binar(int indx);
int			lenght_binar(int index);
void		ft_push_swap(t_element **a);
void		sort_2(t_element **a);
void		sort_3(t_element **a);
void		sort_4(t_element **a);
void		sort_5(t_element **a);
int			ft_lenght(t_element **a);
void		ft_reset_indx(int max_binar, t_element **a);
int			val_pos(t_element *lst, int pos);
int			small_num_indx(t_element **a);
int			len_arg(t_element **a);
int			check_sorted(t_element **a);
int			duplicate_check(t_element **a);
void		big_sort(t_element **a);
void		start_sort(t_element **a);
void		ft_set_indx(t_element **a);
void		*ft_calloc(size_t nelem, size_t elsize);
void		ft_input(char **argv, char **input);
char		**ft_split(const char *s, char c);
char		*ft_strdup(const char *s1);
void		ft_free_array(char **str);
char		*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlenn(const char *s);

#endif