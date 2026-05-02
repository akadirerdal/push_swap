/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:21:33 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 02:53:00 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, t_counter *counter)
{
	t_node	*one;
	t_node	*two;

	if (!a || !*a || !(*a)->next)
		return ;
	one = *a;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*a = two;
	write(1, "sa\n", 3);
	if (counter)
	{
		counter->sa++;
		counter->total++;
	}
}
