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

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_config	cfg;
	t_counter	c;
	int			start;
	double		disorder;

	if (ac < 2)
		return (0);

	counter_init(&c);
	b = NULL;

	start = parse_flags(ac, av, &cfg);

	a = init_stack(av + start);
	if (!a)
		return (0);

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