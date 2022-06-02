/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:14:25 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/05 19:09:53 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ra(t_element **a, int n)
{
	t_element	*head;
	t_element	*last;

	head = *a;
	last = *a;
	if (*a == NULL)
	{
		*a = head;
	}
	else
	{
		*a = head->next;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = head;
		head->next = NULL;
	}
	if (n == 1)
		write (1, "ra\n", 3);
}

void	rb(t_element **b, int n)
{
	t_element	*head;
	t_element	*last;

	head = *b;
	last = *b;
	if (*b == NULL)
	{
		*b = head;
	}
	else
	{
		*b = head->next;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = head;
		head->next = NULL;
	}
	if (n == 1)
		write (1, "rb\n", 3);
}

void	rr(t_element **a, t_element **b)
{
	ra(a, 0);
	rb(b, 0);
	write (1, "rr\n", 3);
}
