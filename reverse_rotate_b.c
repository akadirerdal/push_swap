/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 05:18:54 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:54:20 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_node **b, t_counter *counter)
{
	t_node	*head;
	t_node	*end;
	t_node	*end2;

	if (!b || !*b || !(*b)->next)
		return ;
	head = *b;
	end = *b;
	end2 = *b;
	while (end2->next->next != NULL)
		end2 = end2->next;
	while (end->next != NULL)
		end = end->next;
	end2->next = NULL;
	end->next = head;
	*b = end;
	write(1, "rrb\n", 4);
	if (counter)
	{
		counter->rrb++;
		counter->total++;
	}
}
