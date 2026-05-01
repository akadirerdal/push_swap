/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:52:31 by aberdal           #+#    #+#             */
/*   Updated: 2026/05/01 06:53:34 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef enum e_strategy
{
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
}   t_strategy;

typedef struct s_config
{
    t_strategy  strategy;
    int         bench;
}   t_config;

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

int		isnumber(char *str);
void	sort_stack(t_node **a, t_node **b);
int		is_sorted(t_node *a);
int		has_duplicate(t_node *a);
void	free_list(t_node *a);
long	ft_atol(const char *str);
t_node	*new_node(int value);
void	add_back(t_node **a, t_node *new);
int		parse(char	*str, t_node **a);
int		find_min(t_node *a);
int		get_pos(t_node *a, int min);
void 	sort_5(t_node **a, t_node **b, t_counter *c);
void	simple_short(t_node **a, t_node **b);
int		lst_size(t_node *a);
void	sort_2(t_node **a);
void	sort_3(t_node **a, t_counter *c);
void	assign_index(t_node *a);
void	sa(t_node **a, t_counter *counter);
void	sb(t_node **b, t_counter *counter);
void	ss(t_node **a, t_node **b, t_counter *counter);
void	pa(t_node **a, t_node **b, t_counter *counter);
void	pb(t_node **a, t_node **b, t_counter *counter);
void	ra(t_node **a, t_counter *counter);
void	rb(t_node **b, t_counter *counter);
void	rr(t_node **a, t_node **b, t_counter *counter);
void	rra(t_node **a, t_counter *counter);
void	rrb(t_node **b, t_counter *counter);
void	rrr(t_node **a, t_node **b, t_counter *counter);
char	**ft_split(char const *s, char c);
int		parse_strategy(int ac, char **av, t_strategy *s);
t_node  *init_stack(char **av);
void	simple_sort(t_node **a, t_node **b, t_counter *c);
void	radix_sort(t_node **a, t_node **b, t_counter *c);
void	chunk_sort(t_node **a, t_node **b, t_counter *c);
void	adaptive_sort(t_node **a, t_node **b, t_counter *c);
int		parse_flags(int ac, char **av, t_config *cfg);
void    counter_init(t_counter *c);
double  compute_disorder(t_node *a);
void    print_bench(double d, t_strategy s, t_counter *c);
void    free_stack(t_node *a);
int		get_max_bits(t_node *a);

#endif