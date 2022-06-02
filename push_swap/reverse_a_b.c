/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:14:22 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/06 18:10:11 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rra(t_element **a, int n)
{
	t_element	*head;
	t_element	*last;

	head = *a;
	last = *a;
	if (*a == NULL)
	{
		*a = last;
	}
	else
	{
		while (last->next->next != NULL)
		{
			last = last->next;
		}
		head = last->next;
		head->next = *a;
		last->next = NULL;
		*a = head;
	}
	if (n == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_element **b, int n)
{
	t_element	*head;
	t_element	*last;

	head = *b;
	last = *b;
	if (*b == NULL)
	{
		*b = last;
	}
	else
	{
		while (last->next->next != NULL)
		{
			last = last->next;
		}
		head = last->next;
		head->next = *b;
		last->next = NULL;
		*b = head;
	}
	if (n == 1)
		write (1, "rra\n", 4);
}

void	rrr(t_element **a, t_element **b)
{
	rra(a, 0);
	rrb(b, 0);
	write (1, "rrr\n", 4);
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*c;
	unsigned int		i;

	if (!s)
		return (0);
	i = 0;
	c = malloc(len + 1);
	if (c == NULL)
		return (0);
	if (ft_strlenn(s) < start)
	{
		c[i] = '\0';
		return (c);
	}
	while (i < len)
	{
		c[i] = s[start];
		i++;
		start ++;
	}
	c[i] = '\0';
	return (c);
}
