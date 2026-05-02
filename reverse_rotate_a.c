/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 04:59:29 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:51:48 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, t_counter *counter)
{
	t_node	*head;
	t_node	*end;
	t_node	*end2;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	end = *a;
	end2 = *a;
	while (end2->next->next != NULL)
		end2 = end2->next;
	while (end->next != NULL)
		end = end->next;
	end2->next = NULL;
	end->next = head;
	*a = end;
	write(1, "rra\n", 4);
	if (counter)
	{
		counter->rra++;
		counter->total++;
	}
}
