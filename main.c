/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:48:21 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 00:48:21 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_list(t_node *a)
{
	#include <stdio.h>
	t_node *curr;

	curr = a;
	while (curr)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	t_counter	c;
	int i;
	int			start;
	double		disorder;

	if (ac < 2)
		return (0);

	counter_init(&c);
	b = NULL;
	a = NULL;
	start = parse_flags(ac, av, &cfg);

	i = 1;
	while (av[i])
	{
		if (init_stack(av[i], &a))
			return (1);
		i++;
	}
	print_list(a);
	assign_index(a);

	if (has_duplicate(a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (1);
	}

	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}

	disorder = compute_disorder(a);

	if (cfg.strategy == SIMPLE)
		simple_sort(&a, &b, &c);
	else if (cfg.strategy == MEDIUM)
		chunk_sort(&a, &b, &c);
	else if (cfg.strategy == COMPLEX)
		radix_sort(&a, &b, &c);
	else
		adaptive_sort(&a, &b, &c);

	if (cfg.bench)
		print_bench(disorder, cfg.strategy, &c);
	free_stack(a);
	free_stack(b);
	return (0);
}