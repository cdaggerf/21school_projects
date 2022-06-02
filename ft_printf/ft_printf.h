/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:39 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/10/19 01:16:10 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int			min;
	int			zero;
	int			wid;
	int			precis;
	int			type;
}				t_flags;

t_flags	ft_start_flags(void);
int		ft_printf(const char *format, ...);
int		ft_pars_start(const char *format, va_list arg);
int		ft_print(t_flags *flags, va_list arg);
int		ft_pars_flags(const char *format, \
int *i, t_flags *flags);
int		ft_min(const char *format, int *i, t_flags *flags);
int		ft_wid(const char *format, int *i, t_flags *flags);
int		ft_precis_two(const char *format, int *i, t_flags *flags);
int		ft_precis(const char *format, int *i, t_flags *flags);
int		print_c(char c, t_flags *flags);
int		ft_print_wid(int wid, int zero);
void	ft_putnstr(char *str, int num);
int		print_str(char *str, t_flags *flags);
int		print_id(int num, t_flags *flags);
int		print_pos_id(int num, t_flags *flags);
int		print_neg_id(int n, t_flags *flags);
int		print_u(unsigned int num, t_flags *flags);
char	*ft_itoa_x(unsigned long num);
int		print_x(unsigned int num, t_flags *flags);
char	*ft_itoa_xxx(unsigned long num);
int		print_xxx(unsigned int num, t_flags *flag);
int		pre_point(char *str, int l, t_flags *flags, unsigned long nb);
int		wid_point(char *str, int l, t_flags *flags);
int		print_p(unsigned long nb, t_flags *flags);
int		print_point(char *str, int l, t_flags *flag, unsigned long nb);
void	ft_putstr(char *str);
char	*ft_itoa_two(unsigned int num);

#endif