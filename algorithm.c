/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:34:18 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 21:19:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *a)
{
	int		mistakes;
	int		total;
	t_node	*tmp;

	mistakes = 0;
	total = 0;
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			total++;
			if (a->value > tmp->value)
				mistakes++;
			tmp = tmp->next;
		}
		a = a->next;
	}
	return ((double)mistakes / total);
}

void	simple_sort(t_node **a, t_node **b, t_counter *c)
{
	int	min;
	int	pos;

	while (*a)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		if (pos <= lst_size(*a) / 2)
			while (pos-- > 0)
				ra(a, c);
		else
			while (pos++ < lst_size(*a))
				rra(a, c);
		pb(a, b, c);
	}
	while (*b)
		pa(a, b, c);
}
