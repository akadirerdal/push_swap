/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:21:33 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/04 00:14:17 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **a, t_counter *counter)
{
	t_node *one;
	t_node *two;
	
	if(!a || !*a || !(*a)->next)
		return ;
	one = *a;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*a = two;
	write(1, "sa\n",3);
	if(counter)
	{
		counter->sa++;
		counter->total++;
	}
}