/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 20:08:45 by aberdal           #+#    #+#             */
/*   Updated: 2026-04-12 20:08:45 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static int	count_zero(t_node *a, int bit)
{
	int	count;

	count = 0;
	while (a)
	{
		if (((a->index >> bit) & 1) == 0)
			count++;
		a = a->next;
	}
	return (count);
}

static void	process_bit(t_node **a, t_node **b, int bit)
{
	int	j;
	int	size;
	int	zero_count;

	size = lst_size(*a);
	zero_count = count_zero(*a, bit);
	j = 0;
	while (j < size && zero_count > 0)
	{
		if ((((*a)->index >> bit) & 1) == 0)
		{
			pb(a, b, NULL);
			zero_count--;
		}
		else
			ra(a, NULL);
		j++;
	}
	while (*b)
		pa(a, b, NULL);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		process_bit(a, b, i);
		i++;
	}
}