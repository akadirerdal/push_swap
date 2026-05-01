/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:31:44 by aberdal           #+#    #+#             */
/*   Updated: 2026/04/29 18:03:14 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	raa(t_node **a, t_counter *counter)
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
}*/

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