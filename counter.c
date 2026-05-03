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

void	free_stack(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

static void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

int	limit_control(long num)
{
	return ((num > INT_MAX || num < INT_MIN));
}

void	safe_exit(char **res, t_node *a)
{
	free_split(res);
	free_stack(a);
	write(2, "Error\n", 6);
	exit (1);
}

int	init_stack(char *str, t_node **a)
{
	long	num;
	char	**res;
	int		i;

	res = ft_split(str, ' ');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		if (!isnumber(res[i]))
			safe_exit(res, *a);
		num = ft_atol(res[i]);
		if (limit_control(num))
			safe_exit(res, *a);
		add_back(a, new_node((int)num));
		i++;
	}
	free_split(res);
	return (0);
}
