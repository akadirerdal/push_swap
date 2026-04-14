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

int		isnumber(char *str);
int		is_sorted(t_node *a);
void	free_list(t_node *a);
long	ft_atol(const char *str);
void	chunk_sort(t_node **a, t_node **b);
t_node	*new_node(int value);
void	add_back(t_node **a, t_node *new);
t_node	*parse(int argc, char **argv);
void	chunk_sort(t_node **a, t_node **b);
int		find_min(t_node *a);
int		get_pos(t_node *a, int min);
void	sort_5(t_node **a, t_node **b);
void	simple_short(t_node **a, t_node **b);
int		lst_size(t_node *a);
void	sort_3(t_node **a);
void	assign_index(t_node *a);
void	radix_sort(t_node **a, t_node **b);
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

#endif