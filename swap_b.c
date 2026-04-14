/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:22:50 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 02:31:18 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sb(t_node **b, t_counter *counter)
{
	t_node	*one;
	t_node	*two;

	if (!b || !*b || !(*b)->next)
		return ;
	one = *b;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*b = two;
	write(1, "sb\n", 3);
	if (counter)
	{
		counter->sb++;
		counter->total++;
	}
}
