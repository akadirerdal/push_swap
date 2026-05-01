/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:40:47 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 05:32:28 by aberdal          ###   ########.fr       */
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

int		parse(char *str, t_node **a)
{
	char		**res;
	long		val;
	int			i;

	res = ft_split(str, ' ');
	if (!res)
		return (1);
	i = 0;
	while (res[i])
	{
		if (res[i][0] == '\0')
			return (1);
		if (!isnumber(res[i]))
			return (1);
		val = ft_atol(res[i]);
		if (val > 2147483647 || val < -2147483648)
			return (1);
		if (dublicate(*a, (int)val))
			return (1);
		add_back(a, new_node((int)val));
		i++;
	}
	return (0);
}

int parse_flags(int ac, char **av, t_config *cfg)
{
    int i;

    i = 1;
    cfg->strategy = ADAPTIVE;
    cfg->bench = 0;

    while (i < ac)
    {
        if (strncmp(av[i], "--bench", 7) == 0)
            cfg->bench = 1;
        else if (strncmp(av[i], "--simple", 8) == 0)
            cfg->strategy = SIMPLE;
        else if (strncmp(av[i], "--medium", 8) == 0)
            cfg->strategy = MEDIUM;
        else if (strncmp(av[i], "--complex", 9) == 0)
            cfg->strategy = COMPLEX;
        else if (strncmp(av[i], "--adaptive", 10) == 0)
            cfg->strategy = ADAPTIVE;
        else
            break;
        i++;
    }
    return (i);
}