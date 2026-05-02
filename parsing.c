/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:40:47 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 21:19:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(int ac, char **av, t_config *cfg)
{
	int	i;

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
			break ;
		i++;
	}
	return (i);
}
