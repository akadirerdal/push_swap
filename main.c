/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:48:21 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 21:19:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	control(t_node *a)
{
	if (has_duplicate(a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		exit(1);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		exit(1);
	}
}

void	chooser(t_node **a, t_node **b, t_counter *c, t_config cfg)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (cfg.strategy == SIMPLE)
		simple_sort(a, b, c);
	else if (cfg.strategy == MEDIUM)
		chunk_sort(a, b, c);
	else if (cfg.strategy == COMPLEX)
		radix_sort(a, b, c);
	else
		adaptive_sort(a, b, c);
	if (cfg.bench)
		print_bench(disorder, cfg.strategy, c);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_counter	c;
	t_config	cfg;
	int			start;

	if (ac < 2)
		return (0);
	counter_init(&c);
	b = NULL;
	a = NULL;
	start = parse_flags(ac, av, &cfg);
	while (av[start])
	{
		if (init_stack(av[start], &a))
		{
			free_stack(a);
			return (1);
		}
		start++;
	}
	control(a);
	assign_index(a);
	chooser(&a, &b, &c, cfg);
	free_stack(a);
	free_stack(b);
	return (0);
}
