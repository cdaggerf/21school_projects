/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:39:59 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/11 21:09:37 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_set_indx(t_element **a)
{
	t_element	*head;
	t_element	*head2;
	int			indx;
	int			max_binar;

	head = *a;
	max_binar = 0;
	while (head != NULL)
	{
		head2 = *a;
		indx = 0;
		while (head2 != NULL)
		{
			if (head->value > head2->value)
				indx++;
			head2 = head2->next;
		}
		head->binar = to_binar(indx);
		if (ft_strlen(head->binar) > max_binar)
			max_binar = ft_strlen(head->binar);
		head = head->next;
	}
	ft_reset_indx(max_binar, a);
}

void	start_sort(t_element **a)
{
	int	i;

	i = ft_lenght(a);
	ft_set_indx(a);
	if (i == 2)
		sort_2(a);
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a);
	else if (i == 5)
		sort_5(a);
	else
		big_sort(a);
}

void	ft_push_swap(t_element **a)
{
	if (check_sorted(a))
	{
		exit(1);
	}
	else if (duplicate_check(a))
		ft_error();
	else
		start_sort(a);
}

void	free_list(t_element **list)
{
	t_element	*tmp;

	while (*list)
	{
		tmp = *list;
		free(tmp->binar);
		*list = (*list)->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_element	*a;
	int			i;
	char		**input;

	a = NULL;
	i = 0;
	input = ft_calloc(501, sizeof(char *));
	ft_input(argv, input);
	if (argc > 1)
	{
		while (input[i])
		{
			if (ft_isdigit(input[i]) && ft_strlen(input[i]) < 12)
				ft_lstadd_back(&a, ft_lstnew(ft_atoi(input[i])));
			else
				ft_error();
			i++;
		}
		ft_push_swap(&a);
		free_list(&a);
	}
}
