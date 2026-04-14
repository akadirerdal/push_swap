/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:26:18 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 03:28:33 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b, t_counter *counter)
{
	t_node	*one;
	t_node	*two;

	if (!a || !*a)
		return ;
	one = *b;
	two = *a;
	*a = two->next;
	two->next = one;
	*b = two;
	write(1,"pb\n", 3);
	if (counter)
	{
		counter->pb++;
		counter->total++;
	}
}