/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 04:36:58 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 04:38:07 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b, t_counter *counter)
{
	t_node *head;
	t_node *end;
	
	if(!b || !*b || !(*b)->next)
		return ;
	head = *b;
	end = *b;
	while(end->next != NULL)
		end = end->next;
	*b = head->next;
	end->next = head;
	head->next = NULL;
	write(1,"rb\n",3);
	if(counter)
	{
		counter->rb++;
		counter->total++;
	}
}