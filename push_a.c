/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:11:19 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 03:23:42 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b, t_counter *counter)
{
	t_node	*one;
	t_node	*two;

	if (!b || !*b)
		return ;
	one = *a;
	two = *b;
	*b = two->next;
	two->next = one;
	*a = two;
	write(1,"pa\n", 3);
	if (counter)
	{
		counter->pa++;
		counter->total++;
	}
}