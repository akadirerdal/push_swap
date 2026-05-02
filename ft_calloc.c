/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:04:29 by sukonukc          #+#    #+#             */
/*   Updated: 2026/05/02 02:49:10 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*a;
	size_t			i;

	if (nmemb == 0 && size == 0)
		return (malloc(1));
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
