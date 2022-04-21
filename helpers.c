/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:33:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 17:21:47 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	typequotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			return (34);
		else if (str[i] == 39)
			return (39);
		i++;
	}
	return (0);
}

int	quotespy(char *str, int help)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i] && help == 2)
	{
		if (str[i] == 34)
			c++;
		i++;
	}
	while (str[i] && help == 1)
	{
		if (str[i] == 39)
			c++;
		i++;
	}
	return (c);
}

int	findquotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			return (i);
		else if (str[i] == 39)
			return (i);
		i++;
		printf("First quote %d\n", i);
	}
	return (0);
}

int	helperspace(char *str, int help)
{
	int	i;

	i = 0;
	if (help == 0)
	{
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
		return (i);
	}
	if (help == 1)
	{
		while (str[i] == ' ' && str[i])
			i++;
		return (i);
	}
	if (help == 2)
	{
		while (str[i] != ' ' && str[i])
			i++;
		return (i);
	}
	return (0);
}
