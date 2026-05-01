/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 18:26:36 by aberdal           #+#    #+#             */
/*   Updated: 2026-04-12 18:26:36 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *a)
{
	int	min;

	if (!a)
		return (0);
	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	get_pos(t_node *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == min)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}