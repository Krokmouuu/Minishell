/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:01:43 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 19:52:00 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip2(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 34)
	{
		i++;
		while (str[i] != 34 && str[i])
			i++;
	}
	else if (str[i] == 39)
	{
		i++;
		while (str[i] != 39 && str[i])
			i++;
	}
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	return (&str[i]);
}

char	*takingnoquote(char *str, char quote)
{
	int		i;
	int		j;
	char	*test;

	test = ft_calloc(1000, 1);
	i = 0;
	j = i;
	while (str[i])
	{
		if (str[i] != quote)
			test[j++] = str[i++];
		if (str[i] == quote)
			i++;
	}
	test[j] = '\0';
	return (test);
}

int	lenwithoutquote(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != 34 && str[j] != 39)
			i++;
		j++;
	}
	return (i);
}
