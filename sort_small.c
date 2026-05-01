/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:47:51 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 05:19:10 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5(t_node **a, t_node **b, t_counter *c)
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
	sort_3(a , c);
	while (*b)
		pa(a, b, NULL);
}
