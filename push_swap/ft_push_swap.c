/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:38:18 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/06 19:21:05 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_2(t_element **a)
{
	ra(a, 1);
}

void	sort_3(t_element **a)
{
	t_element	*head;

	head = *a;
	if (val_pos(head, 0) > val_pos(head, 1) && val_pos(head, 0) < val_pos(head,
			2) && val_pos(head, 1) < val_pos(head, 2))
		sa(a, 1);
	else if (val_pos(head, 0) > val_pos(head, 1) && val_pos(head,
			0) > val_pos(head, 2) && val_pos(head, 1) > val_pos(head, 2))
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (val_pos(head, 0) > val_pos(head, 1) && val_pos(head,
			0) > val_pos(head, 2) && val_pos(head, 1) < val_pos(head, 2))
		ra(a, 1);
	else if (val_pos(head, 0) < val_pos(head, 1) && val_pos(head,
			0) < val_pos(head, 2) && val_pos(head, 1) > val_pos(head, 2))
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (val_pos(head, 0) < val_pos(head, 1) && val_pos(head,
			0) > val_pos(head, 2) && val_pos(head, 1) > val_pos(head, 2))
		rra(a, 1);
}

void	sort_4(t_element **a)
{
	int			i;
	int			j;
	t_element	*b;

	b = NULL;
	i = small_num_indx(a);
	j = (ft_lenght(a)) / 2;
	if (j <= i)
	{
		while (i < ft_lenght(a))
		{
			rra(a, 1);
			i++;
		}
	}
	else
	{
		while (i-- > 0)
			ra(a, 1);
	}
	pb(a, &b);
	sort_3(a);
	pa(a, &b);
}

void	sort_5(t_element **a)
{
	int			i;
	int			j;
	t_element	*b;

	b = NULL;
	i = small_num_indx(a);
	j = (ft_lenght(a)) / 2;
	if (j <= i)
	{
		while (i < ft_lenght(a))
		{
			rra(a, 1);
			i++;
		}
	}
	else
	{
		while (i-- > 0)
			ra(a, 1);
	}
	pb(a, &b);
	sort_4(a);
	pa(a, &b);
}

void	big_sort(t_element **a)
{
	int			i;
	int			len;
	int			lenpb;
	t_element	*b;

	b = NULL;
	i = ft_strlen((*a)->binar);
	while (--i >= 0)
	{
		len = len_arg(a);
		lenpb = 0;
		while (len -- > 0)
		{
			if ((*a)->binar[i] == '0')
			{
				pb(a, &b);
				lenpb++;
			}
			else
				ra(a, 1);
		}
		while (lenpb -- > 0)
			pa(a, &b);
	}
}
