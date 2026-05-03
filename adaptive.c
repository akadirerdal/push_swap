/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 05:08:08 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 05:08:08 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a, t_counter *c)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, c);
	else if (first > second && second > third)
	{
		sa(a, c);
		rra(a, c);
	}
	else if (first > second && second < third && first > third)
		ra(a, c);
	else if (first < second && second > third && first < third)
	{
		sa(a, c);
		ra(a, c);
	}
	else if (first < second && second > third && first > third)
		rra(a, c);
}

void	big_sorts(double d, t_node **a, t_node **b, t_counter *c)
{
	if (d < 0.2)
		simple_sort(a, b, c);
	else if (d < 0.5)
		chunk_sort(a, b, c);
	else
		radix_sort(a, b, c);
}

void	adaptive_sort(t_node **a, t_node **b, t_counter *c)
{
	int	size;

	size = lst_size(*a);
	assign_index(*a);
	if (size <= 5)
		simple_sort(a, b, c);
	else if (size <= 100)
		radix_sort(a, b, c);
	else
		radix_sort(a, b, c);
}
