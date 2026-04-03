/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberdal <aberdal@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:35:17 by aberdal           #+#    #+#             */
/*   Updated: 2026/03/30 18:35:17 by aberdal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *a;

    if(argc < 2)
        return (0);
    a = parse(argc, argv);
    if (!a)
    {
        write(2 ,"Error\n", 6);
        return (1);
    }
    return (0);
}