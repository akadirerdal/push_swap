/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-13 23:27:22 by aberdal           #+#    #+#             */
/*   Updated: 2026-04-13 23:27:22 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max(t_node *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static int	get_pos_max(t_node *b)
{
	int	max;
	int	pos;

	max = get_max(b);
	pos = 0;
	while (b)
	{
		if (b->index == max)
			return (pos);
		b = b->next;
		pos++;
	}
	return (0);
}

static void	push_chunks(t_node **a, t_node **b, int chunk)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, NULL);
			rb(b, NULL);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b, NULL);
			if (*b && (*b)->next && (*b)->index < (i + chunk / 2))
				rb(b, NULL);
			i++;
		}
		else
			ra(a, NULL);
	}
}

static void	push_back(t_node **a, t_node **b)
{
	int	pos;
	int	size_b;
	int	rev;

	while (*b)
	{
		pos = get_pos_max(*b);
		size_b = lst_size(*b);
		if (pos <= size_b / 2)
			while (pos-- > 0)
				rb(b, NULL);
		else
		{
			rev = size_b - pos;
			while (rev-- > 0)
				rrb(b, NULL);
		}
		pa(a, b, NULL);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk;

	size = lst_size(*a);
	if (size <= 100)
		chunk = 10;
	else
		chunk = 23;
	push_chunks(a, b, chunk);
	push_back(a, b);
}
