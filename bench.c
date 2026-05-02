/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:51:20 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/02 21:19:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(int fd, const char *s)
{
	while (*s)
		write(fd, s++, 1);
}

void	put_nbr(int fd, int n)
{
	char	buf[12];
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		buf[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i--)
		write(fd, &buf[i], 1);
}

void	put_double_percent(int fd, double d)
{
	int	val;
	int	int_part;
	int	frac;

	val = (int)(d * 10000);
	int_part = val / 100;
	frac = val % 100;
	put_nbr(fd, int_part);
	write(fd, ".", 1);
	if (frac < 10)
		write(fd, "0", 1);
	put_nbr(fd, frac);
}

const char	*get_complexity(t_strategy s, double d)
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
	print_bench_header(d, s);
	print_bench_total(c);
	print_bench_ops(c);
}