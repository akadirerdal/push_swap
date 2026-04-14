/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 05:21:26 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 05:48:25 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_reverse_rotate(t_node **ab)
{
	t_node	*head;
	t_node	*end;
	t_node	*end2;

	if (!ab || !*ab || !(*ab)->next)
		return ;
	head = *ab;
	end = *ab;
	end2 = *ab;
	while (end2->next->next != NULL)
		end2 = end2->next;
	while (end->next != NULL)
		end = end->next;
	end2->next = NULL;
	end->next = head;
	*ab = end;
}

void	rrr(t_node **a, t_node **b, t_counter *counter)
{
	swap_reverse_rotate(a);
	swap_reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (counter)
	{
		counter->rrr++;
		counter->total++;
	}
}