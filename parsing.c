/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:28 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/11 17:43:49 by bleroy           ###   ########.fr       */
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

char	*ft_get_files(char *str)
{
	char	*files;
	int		i;
	int		j;

	files = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i] && str[i] != '|')
	{
		files[j] = str[i];
		i++;
		j++;
	}
	files[j] = '\0';
	printf("Files -> %s\n", files);
	return (files);
}

char	*ft_get_flags(char *str, t_parse *parse)
{
	char	*flag;
	int		i;
	int		j;

	flag = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == ' ' && str[i + 1] == '-' && str[i + 2] == ' ')
		{
			parse->token->files = ft_get_files(&str[++i]);
			break ;
		}
		else if (str[i] == ' ' && str[i + 1] != '-'
			&& str[i + 1] != '\0' && str[i + 1] != '|')
		{
			parse->token->files = ft_get_files(&str[++i]);
			break ;
		}
		flag[j++] = str[i++];
	}
	flag[j] = '\0';
	printf("Flag -> %s\n", flag);
	return (flag);
}

//! COMMANDE RECUPERER, GESTION DE FLAG A FAIRE
void	splitinput(t_parse *parse)
{
	int		i;
	int		j;

	parse->token->cmd = ft_calloc(ft_strlen(parse->token->input) + 1,
			sizeof(char));
	j = 0;
	i = 0;
	while (parse->token->input[i] != ' ' && parse->token->input[i] != '\0')
	{
		parse->token->cmd[j] = parse->token->input[i];
		i++;
		j++;
	}
	parse->token->cmd[j] = '\0';
	printf("Cmd -> %s\n", parse->token->cmd);
	if (parse->token->input[i] == ' ')
	{
		i++;
		if (parse->token->input[i] != '-'
			|| (parse->token->input[i] == '-'
				&& parse->token->input[i + 1] == ' '))
			parse->token->files = ft_get_files(&parse->token->input[i]);
		else if (parse->token->input[i] == '-'
			&& parse->token->input[i + 1] != ' ')
			parse->token->flag = ft_get_flags(&parse->token->input[i], parse);
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
	{
		cmd[j++] = str[i++];
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
