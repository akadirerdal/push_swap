/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 02:30:38 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 02:30:38 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counter_init(t_counter *c)
{
	c->sa = 0; c->sb = 0; c->ss = 0;
	c->pa = 0; c->pb = 0;
	c->ra = 0; c->rb = 0; c->rr = 0;
	c->rra = 0; c->rrb = 0; c->rrr = 0;
	c->total = 0;
}
static const char	*get_complexity(t_strategy s, double d)
{
	if (s == SIMPLE)
		return ("O(n^2)");
	else if (s == MEDIUM)
		return ("O(n sqrt(n))");
	else if (s == COMPLEX)
		return ("O(n log n)");
	else
	{
		if (d < 0.2)
			return ("O(n^2)");
		else if (d < 0.5)
			return ("O(n sqrt(n))");
		else
			return ("O(n log n)");
	}
}
void	print_bench(double d, t_strategy s, t_counter *c)
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

	dprintf(2, "[bench] disorder: %.2f%%\n", d * 100);
	dprintf(2, "[bench] strategy: %s (%s)\n",name,get_complexity(s, d));
	dprintf(2, "[bench] total_ops: %d\n", c->total);

	dprintf(2, "[bench] sa:%d sb:%d ss:%d\n", c->sa, c->sb, c->ss);
	dprintf(2, "[bench] pa:%d pb:%d\n", c->pa, c->pb);
	dprintf(2, "[bench] ra:%d rb:%d rr:%d\n", c->ra, c->rb, c->rr);
	dprintf(2, "[bench] rra:%d rrb:%d rrr:%d\n", c->rra, c->rrb, c->rrr);
}

void free_stack(t_node *a)
{
    t_node *tmp;

    while (a)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
}

t_node *init_stack(char **av)
{
	t_node	*a;
	long	num;
	int		i;

	a = NULL;
	i = 0;
	while (av[i])
	{
		if (!isnumber(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		add_back(&a, new_node((int)num));
		i++;
	}
	return (a);
}