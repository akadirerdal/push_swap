/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnklst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 01:54:15 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/30 18:34:41 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if(!new_node)
        return (NULL);
    new_node -> value = value;
    new_node -> next = NULL;
    return (new_node);
}

void    add_back(t_node **a, t_node *new)
{
    t_node *tmp;

    if (!*a)
    {
        *a = new;
        return ;
    }
    tmp = *a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int lst_size(t_node *a)
{
    int i;

    i = 0;
    while(a)
    {
        i++;
        a = a->next;
    }
    return (i);
}
