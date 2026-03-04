/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 03:31:44 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 03:51:03 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_counter *counter)
{
	t_node *head;
	t_node *end;
	
	if(!a || !*a || !(*a)->next)
		return ;
	head = *a;
	end = *a;
	while(end->next != NULL)
		end = end->next;
	*a = head->next;
	end->next = head;
	head->next = NULL;
	write(1,"ra\n",3);
	if(counter)
	{
		counter->ra++;
		counter->total++;
	}
}