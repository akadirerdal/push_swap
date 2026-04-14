/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-13 21:47:51 by aberdal           #+#    #+#             */
/*   Updated: 2026-04-13 21:47:51 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a, NULL);
	else if (first > second && second > third)
	{
		sa(a, NULL);
		rra(a, NULL);
	}
	else if (first > second && second < third && first > third)
		ra(a, NULL);
	else if (first < second && second > third && first < third)
	{
		sa(a, NULL);
		ra(a, NULL);
	}
	else if (first < second && second > third && first > third)
		rra(a, NULL);
}

void	sort_5(t_node **a, t_node **b)
{
	int	min;
	int	pos;

	while (lst_size(*a) > 3)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		if (pos == 0)
			pb(a, b, NULL);
		else if (pos <= lst_size(*a) / 2)
			ra(a, NULL);
		else
			rra(a, NULL);
	}
	sort_3(a);
	while (*b)
		pa(a, b, NULL);
}
