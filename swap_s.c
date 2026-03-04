/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 02:58:53 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 03:08:41 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_node **ab)
{
	t_node *one;
	t_node *two;
	
	if (!ab || !*ab || !(*ab)->next)
		return ;
	one = *ab;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*ab = two;
}
void	ss(t_node **a, t_node **b, t_counter *counter)
{
	swap_stack(a);
	swap_stack(b);
	write(1,"ss\n",3);
	if (counter)
	{
		counter->ss++;
		counter->total++;
	}
}