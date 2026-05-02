/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukonukc <sukonukc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:32:26 by sukonukc          #+#    #+#             */
/*   Updated: 2026/05/02 02:47:43 by sukonukc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	wlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*copy(char const *s, int i, int len)
{
	char	*word;
	int		j;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	*free_all(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;

	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), (wcount(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[w++] = copy(s, i, wlen(s, c, i));
			if (str[w - 1] == NULL)
				return (free_all(str));
			i += wlen(s, c, i);
		}
		else
			i++;
	}
	return (str);
}
