/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:33:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/16 19:05:00 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	int		n;
	char	*cmd;

	j = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	n = i;
	while (str[i] != '\0')
		i++;
	cmd = ft_calloc(i + 1, 1);
	while (str[n] != '\0')
		cmd[j++] = str[n++];
	cmd[j] = '\0';
	return (cmd);
}

int	whitespace(char *str)
{
	int	i;

	i = 0;
	g_struct.doublequote = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
		i++;
	return (i);
}

int	double_quote(t_token *temp, char *str)
{
	int		i;
	char	*test;
	int		j;

	j = 0;
	i = lenwithoutquote(str);
	test = ft_calloc(i + 1, 1);
	i = 1;
	while (str[i])
	{
		while (str[i] == SQUOTE && str[i])
			i++;
		while (str[i] != DQUOTE && str[i] != SQUOTE && str[i])
			test[j++] = str[i++];
		if ((str[i] == DQUOTE && str[i + 1] == ' ' && str[i + 1] != '\0')
			|| (str[i] == DQUOTE && str[i + 1] == '\0'))
			break ;
		i++;
	}
	test[j] = '\0';
	if (test[0] == '\0')
		return (0);
	temp->args = test;
	temp->quoted = 2;
	return (i);
}

int	single_quote(t_token *temp, char *str)
{
	int		i;
	char	*test;
	int		j;

	j = 0;
	i = lenwithoutquote(str);
	test = ft_calloc(i + 1, 1);
	i = 1;
	while (str[i])
	{
		while (str[i] == DQUOTE && str[i])
			i++;
		while (str[i] && str[i] != DQUOTE && str[i] != SQUOTE)
			test[j++] = str[i++];
		if ((str[i] == SQUOTE && str[i + 1] == ' ' && str[i + 1] != '\0')
			|| (str[i] == SQUOTE && str[i + 1] == '\0'))
			break ;
		i++;
	}
	test[j] = '\0';
	if (test[0] == '\0')
		return (0);
	temp->args = test;
	temp->quoted = 1;
	return (i);
}

int	helperspace(char *str, int help)
{
	int	i;

	i = 0;
	if (help == 0 || help == 2)
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
	return (0);
}
