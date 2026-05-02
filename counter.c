/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 02:30:38 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 21:19:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counter_init(t_counter *c)
{
	c->sa = 0;
	c->pa = 0;
	c->pb = 0;
	c->ra = 0;
	c->rb = 0;
	c->rra = 0;
	c->rrb = 0;
	c->total = 0;
}

void	free_stack(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

static void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

int	init_stack(char *str, t_node **a)
{
	long	num;
	char	**res;
	int		i;

	res = ft_split(str, ' ');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		if (!isnumber(res[i]))
		{
			write(2, "Error\n", 6);
			free_split(res);
			free_stack(*a);
			*a = NULL;
			return (1);
		}
		num = ft_atol(res[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(2, "Error\n", 6);
			free_split(res);
			free_stack(*a);
			*a = NULL;
			return (1);
		}
		add_back(a, new_node((int)num));
		i++;
	}
	free_split(res);
	return (0);
}
