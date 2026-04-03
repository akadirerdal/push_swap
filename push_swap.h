/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:52:31 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/03 22:19:55 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_counter;

int	isnumber(char *str);
long	ft_atol(const char *str);
t_node	*new_node(int value);
void	add_back(t_node **a, t_node *new);
t_node	*parse(int argc, char **argv);
int find_min(t_node *a);
int get_pos(t_node *a, int min);
void simple_short(t_node **a, t_node **b);
int lst_size(t_node *a);

#endif