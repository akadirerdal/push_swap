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
		if (ft_strncmp(av[i], "--bench", 7) == 0)
			cfg->bench = 1;
		else if (ft_strncmp(av[i], "--simple", 8) == 0)
			cfg->strategy = SIMPLE;
		else if (ft_strncmp(av[i], "--medium", 8) == 0)
			cfg->strategy = MEDIUM;
		else if (ft_strncmp(av[i], "--complex", 9) == 0)
			cfg->strategy = COMPLEX;
		else if (ft_strncmp(av[i], "--adaptive", 10) == 0)
			cfg->strategy = ADAPTIVE;
		else
			break ;
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
