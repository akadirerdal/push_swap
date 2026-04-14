/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:35:17 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/30 18:35:17 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = lst_size(*a);
	assign_index(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
		chunk_sort(a, b);
}

void	free_list(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = parse(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	sort_stack(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
