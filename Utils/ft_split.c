/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:15:14 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 19:32:22 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_countwords(char *str, char sep)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && i < ft_strlen(str))
				i++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	return (count);
}

static size_t	ft_findend(char *str, char c, int i)
{
	if (str[i] == c)
	{
		while (str[i] == c)
			i++;
	}
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static size_t	ft_findstart(char *str, char c, int i)
{
	while (str[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	nb_words;
	size_t	end_word;
	size_t	start_word;

	if (!s)
		return (NULL);
	i = 0;
	start_word = 0;
	end_word = 0;
	tab = NULL;
	nb_words = ft_countwords((char *) s, c);
	tab = (char **)ft_calloc(nb_words + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (i < nb_words)
	{
		start_word = ft_findstart((char *)s, c, end_word);
		end_word = ft_findend((char *)s, c, start_word);
		tab[i++] = ft_substr((char *)s, start_word, (end_word - start_word));
	}
	tab[i] = NULL;
	return (tab);
}
