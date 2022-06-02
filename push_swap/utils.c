/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:59:17 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/03 21:16:51 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	i += ((str[0] == '-' || str[0] == '+') && str[1]);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

t_element	*ft_lstnew(int value)
{
	t_element	*new_list;

	new_list = malloc(sizeof(t_element));
	if (new_list == 0)
		return (0);
	new_list->value = value;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_element **list_shell, t_element *new)
{
	t_element	*ptr_list_shell;

	ptr_list_shell = *list_shell;
	if (*list_shell == NULL)
	{
		*list_shell = new;
		new->next = NULL;
	}
	else
	{
		while (ptr_list_shell->next)
			ptr_list_shell = ptr_list_shell->next;
		ptr_list_shell->next = new;
		new->next = NULL;
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}
