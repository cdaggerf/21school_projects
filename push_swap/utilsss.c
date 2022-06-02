/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaggerf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:22:43 by cdaggerf          #+#    #+#             */
/*   Updated: 2021/12/04 20:36:33 by cdaggerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(ft_strlen(s1) + 1);
	if (s == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_input(char **argv, char **input)
{
	char		**split;
	int			j;
	int			i;
	int			end;

	end = 0;
	j = 1;
	i = 0;
	while (argv[j] != NULL)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i] != NULL)
		{
			input[end] = ft_strdup(split[i]);
			i++;
			end++;
		}
		ft_free_array(split);
		j++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)malloc(nelem * elsize);
	if (ptr == NULL)
		return (0);
	while (i < nelem * elsize)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_getsign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = ft_getsign(str, &i);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res > 2147483648 && sign == -1)
		|| (res > 2147483647 && sign == 1))
		exit (write(1, "Error\n", 6));
	return (res * sign);
}
