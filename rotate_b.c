/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 04:36:58 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:52:30 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b, t_counter *counter)
{
	t_node	*head;
	t_node	*end;

	if (!b || !*b || !(*b)->next)
		return ;
	head = *b;
	end = *b;
	while (end->next != NULL)
		end = end->next;
	*b = head->next;
	end->next = head;
	head->next = NULL;
	write(1, "rb\n", 3);
	if (counter)
	{
		counter->rb++;
		counter->total++;
	}
}
