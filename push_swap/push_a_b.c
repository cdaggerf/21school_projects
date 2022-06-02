/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:14:18 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/03 21:11:18 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_element **a, t_element **b)
{
	t_element	*head2;

	if (*b)
	{
		head2 = *b;
		*b = head2->next;
		if (*a)
		{
			head2->next = *a;
			*a = head2;
		}
		else
		{
			head2->next = NULL;
			*a = head2;
		}
	}
	write (1, "pa\n", 3);
}

void	pb(t_element **a, t_element **b)
{
	t_element	*head2;

	if (*a)
	{
		head2 = *a;
		*a = head2->next;
		if (*b)
		{
			head2->next = *b;
			*b = head2;
		}
		else
		{
			head2->next = NULL;
			*b = head2;
		}
	}
	write (1, "pb\n", 3);
}

int	ft_lenght(t_element **a)
{
	t_element	*head;
	int			i;

	i = 0;
	head = *a;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	lenght_binar(int indx)
{
	int		i;

	i = 0;
	while (indx > 0)
	{
		indx = indx / 2;
		i++;
	}
	return (i);
}

char	*to_binar(int indx)
{
	char	*str;
	int		i;

	if (indx == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		i = lenght_binar(indx);
		str = malloc(sizeof(char) * i + 1);
		str[i] = '\0';
		while (indx > 0)
		{
			str[--i] = indx % 2 + 48;
			indx = indx / 2;
		}
	}
	return (str);
}
