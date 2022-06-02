/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:14:27 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/05 19:22:17 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sa(t_element **a, int n)
{
	t_element	*head;
	t_element	*swap;

	if (a && (*a)->next)
	{
		head = *a;
		swap = head->next;
		head->next = swap->next;
		swap->next = head;
		*a = swap;
	}
	if (n == 1)
		write(1, "sa\n", 3);
}

void	sb(t_element **b, int n)
{
	t_element	*head;
	t_element	*swap;

	if (b && (*b)->next)
	{
		head = *b;
		swap = head->next;
		head->next = swap->next;
		swap->next = head;
		*b = swap;
	}
	if (n == 1)
		write (1, "sb\n", 3);
}

void	ss(t_element **a, t_element **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	ft_reset_indx(int max_binar, t_element **a)
{
	int			i;
	int			j;
	char		*str;
	t_element	*head;

	head = *a;
	while (head != NULL)
	{
		i = 0;
		j = 0;
		str = head->binar;
		head->binar = malloc(sizeof(char) * max_binar);
		while (max_binar > i)
		{
			if ((max_binar - ft_strlen(str)) > i)
				head->binar[i] = '0';
			else
				head->binar[i] = str[j++];
			i++;
		}
		free(str);
		head = head->next;
	}
}
