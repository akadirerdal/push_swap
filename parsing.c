/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.tr>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-29 01:40:47 by aberdal           #+#    #+#             */
/*   Updated: 2026-03-29 01:40:47 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	dublicate(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

t_node	*parse(int argc, char **argv)
{
	t_node		*a;
	int long	val;
	int			i;

	i = 0;
	a = NULL;
	while (i < argc)
	{
		if (!is_nuber(argv[i]))
			return (NULL);
		val = ft_atol(argv[i]);
		if (val > 2147483647 || -2147483648)
			return (NULL);
		if (dublicate(a, (int)val))
			return (NULL);
		add_back(&a, new_node((int)val));
		i++;
	}
	return (a);
}
