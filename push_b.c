/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:26:18 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:55:13 by sukonukc         ###   ########.fr       */
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
	write(1, "pb\n", 3);
	if (counter)
	{
		counter->pb++;
		counter->total++;
	}
}
