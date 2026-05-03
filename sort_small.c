/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:47:51 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 23:29:43 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_node **a, t_node **b, t_counter *c)
{
	int	min;
	int	pos;

	while (lst_size(*a) > 3)
	{
		min = find_min(*a);
		pos = get_pos(*a, min);
		if (pos == 0)
			pb(a, b, c);
		else if (pos <= lst_size(*a) / 2)
			ra(a, c);
		else
			rra(a, c);
	}
	sort_3(a, c);
	while (*b)
		pa(a, b, c);
}
