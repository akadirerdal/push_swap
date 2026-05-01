/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 04:39:41 by aberdal           #+#    #+#             */
/*   Updated: 2026/04/23 18:09:12 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_rotate(t_node **ab)
{
	t_node	*head;
	t_node	*end;

	if (!ab || !*ab || !(*ab)->next)
		return ;
	head = *ab;
	end = *ab;
	while (end->next != NULL)
		end = end->next;
	*ab = head->next;
	end->next = head;
	head->next = NULL;
}

void	rr(t_node **a, t_node **b, t_counter *counter)
{
	swap_rotate(a);
	swap_rotate(b);
	write(1, "rr\n", 3);
	if (counter)
	{
		counter->rr++;
		counter->total++;
	}
}