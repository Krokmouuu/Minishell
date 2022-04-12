/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:28 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/12 14:45:17 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n')
		i++;
	return (&str[i]);
}

//! COMMANDE RECUPERER, GESTION DE FLAG A FAIRE
void	splitinput(char *str, t_parse *parse)
{
	int		i;
	int		j;

	parse->token->cmd = ft_calloc(ft_strlen(str) + 1,
			sizeof(char));
	j = 0;
	i = 0;
	parse->token->cmd = ft_get_cmd(str);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (str[i] == '-'
		&& str[i + 1] != ' ' && str[i] != '\0')
		parse->token->flag = ft_get_flags(&str[i], parse);
	else if (str[i] != '-' || ((str[i] == '-' && str[i + 1] == ' ')
			&& str[i] != '\0'))
		parse->token->files = ft_get_files(&str[i]);
	else
	{
		parse->token->flag = ft_strdup("");
		parse->token->files = ft_strdup("");
	}
}

//* Enlève les espaces en trop et prend la string jusqu'à croisé un commentaire
void	fuckwhitespace(t_parse *parse)
{
	int		i;
	char	*str;
	int		j;
	char	*cmd;

	i = 0;
	j = 0;
	cmd = ft_calloc(ft_strlen(parse->input) + 1, sizeof(char));
	str = malloc(((ft_strlen(parse->input) + 1) * sizeof(char)));
	str = parse->input;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		str = whitespace(str);
	while (str[i] != '\0' && str[i] != '#')
		cmd[j++] = str[i++];
	cmd[j] = '\0';
	parse->token->input = cmd;
}
