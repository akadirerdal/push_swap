/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:31:44 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:52:07 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_counter *counter)
{
	t_node	*head;
	t_node	*end;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	end = *a;
	while (end->next != NULL)
		end = end->next;
	*a = head->next;
	end->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
	if (counter)
	{
		counter->ra++;
		counter->total++;
	}
}
