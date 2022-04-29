/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:01:43 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:55:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	lenword(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] && str[i] != DQUOTE && str[i] != SQUOTE)
		i++;
	return (i);
}

int	lenwithoutquote(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != DQUOTE && str[j] != SQUOTE)
			i++;
		j++;
	}
	return (i);
}

int	validquote(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (line[i] && i != index)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (open == 0 && line[i] == '\"')
			open = 1;
		else if (open == 0 && line[i] == '\'')
			open = 2;
		else if (open == 1 && line[i] == '\"')
			open = 0;
		else if (open == 2 && line[i] == '\'')
			open = 0;
		i++;
	}
	return (open);
}

char	*takingnoquote(char *str, char quote)
{
	int		i;
	int		j;
	char	*test;
	char	otherquote;

	i = 0;
	j = 0;
	if (quote == DQUOTE)
		otherquote = SQUOTE;
	else
		otherquote = DQUOTE;
	test = takingnoquotehelper(str, quote, otherquote);
	return (test);
}

char	*takingnoquotehelper(char *str, char q, char oq)
{
	int		i;
	char	*test;
	int		j;

	test = ft_calloc(ft_strlen(str), 1);
	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == q) || (str[i] == q && str[i + 1] == q))
			while (str[i] == q || str[i] == oq)
				i++;
		else if (str[i] == q && str[i + 1] == oq)
		{
			while (str[i] && str[i] != oq)
				test[j++] = str[i++];
			break ;
		}
		else if ((str[i] == q && str[i + 1] == ' ')
			|| (str[i - 1] == q && str[i] == ' '))
			break ;
		else
			test[j++] = str[i++];
	}
	return (test);
}
