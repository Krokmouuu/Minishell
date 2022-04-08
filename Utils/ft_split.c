/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:15:14 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/08 14:36:07 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	nbrstring(const char *str, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (str[i] && str[i] != c)
			{
				while (str[i] && str[i] != c)
					i++;
				check++;
			}
			i++;
		}
	}
	return (check);
}

static char	*lenword(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**split;

	i = 0;
	j = 0;
	start = -1;
	split = malloc(((nbrstring(s, c) + 1) * sizeof(char *)));
	if (!split || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j] = lenword(s, start, i);
			j++;
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
