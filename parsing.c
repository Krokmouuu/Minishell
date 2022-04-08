/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:28 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/08 18:39:40 by bleroy           ###   ########.fr       */
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
void	splitinput(t_parse *parse)
{
	int		i;
	int		j;
	
	parse->token->cmd = ft_calloc(ft_strlen(parse->token->input) + 1, sizeof(char));
	j = 0;
	i = 0;
	while (parse->token->input[i] != ' ' && parse->token->input[i] != '\0')
	{
		parse->token->cmd[j] = parse->token->input[i];
		i++;
		j++;
	}
	parse->token->cmd[j] = '\0';
	// while (parse->token->input[i])
	// {
	// 	if (parse->token->input[i] == '-' && parse->token->input[i + 1] != ' ')
	// 		ft_get_flags(&parse[i]);
	// 	i++;
	// }
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
	{
		cmd[j] = str[i];
		i++;
		j++;
		if (str[i - 1] == ' ')
		{
			while (str[i] == ' ')
				i++;
			cmd[j] = ' ';
		}
	}
	cmd[j] = '\0';
	parse->token->input = cmd;
	splitinput(parse);
}
