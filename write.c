/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:57:43 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 14:57:43 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench_header(double d, t_strategy s)
{
	const char	*name;

	if (s == SIMPLE)
		name = "Simple";
	else if (s == MEDIUM)
		name = "Medium";
	else if (s == COMPLEX)
		name = "Complex";
	else
		name = "Adaptive";
	put_str(2, "[bench] disorder: ");
	put_double_percent(2, d);
	put_str(2, "%\n");
	put_str(2, "[bench] strategy: ");
	put_str(2, name);
	put_str(2, " (");
	put_str(2, get_complexity(s, d));
	put_str(2, ")\n");
}

void	print_bench_total(t_counter *c)
{
	put_str(2, "[bench] total_ops: ");
	put_nbr(2, c->total);
	put_str(2, "\n");
}

void	print_bench_ops(t_counter *c)
{
	put_str(2, "[bench] sa:");
	put_nbr(2, c->sa);
	put_str(2, "\n");
	put_str(2, "[bench] pa:");
	put_nbr(2, c->pa);
	put_str(2, " pb:");
	put_nbr(2, c->pb);
	put_str(2, "\n");
	put_str(2, "[bench] ra:");
	put_nbr(2, c->ra);
	put_str(2, " rb:");
	put_nbr(2, c->rb);
	put_str(2, "\n");
	put_str(2, "[bench] rra:");
	put_nbr(2, c->rra);
	put_str(2, " rrb:");
	put_nbr(2, c->rrb);
	put_str(2, "\n");
}