/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:07:25 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/05 19:46:28 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	val_pos(t_element *lst, int pos)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == pos)
			return (lst->value);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	small_num_indx(t_element **a)
{
	int			pos;
	int			min;
	int			min_indx;
	t_element	*head;

	min = 2147483647;
	min_indx = 0;
	pos = 0;
	head = *a;
	while (head != NULL)
	{
		if (min > head->value)
		{
			min = head->value;
			min_indx = pos;
		}
		head = head->next;
		pos++;
	}
	return (min_indx);
}

int	len_arg(t_element **a)
{
	int			l;
	t_element	*head;

	l = 0;
	head = *a;
	while (head)
	{
		l++;
		head = head->next;
	}
	return (l);
}

int	check_sorted(t_element **a)
{
	t_element	*v;

	v = *a;
	if (a == NULL)
		return (1);
	while (v->next != NULL)
	{
		if (v->value >= v->next->value)
			return (0);
		v = v->next;
	}
	return (1);
}

int	duplicate_check(t_element **a)
{
	int			i;
	t_element	*head;
	t_element	*str;

	i = 0;
	head = *a;
	while (head->next != NULL)
	{
		str = head->next;
		while (str != NULL)
		{
			if (head->value == str->value)
			{
				i++;
				break ;
			}
			str = str->next;
		}
		head = head->next;
	}
	return (i);
}
