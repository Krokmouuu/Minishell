/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:20:39 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/12 14:49:09 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (str[0] == '\0')
		return (NULL);
	files[j] = '\0';
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
		if (str[i] == ' ' && str[i] != '\0')
		{
			while (str[i + 1] == ' ' && str[i + 1] != '\0')
				i++;
		}
		if ((str[i] == '-' && str[i + 1] == ' ') || (str[i] == '-' && str[i + 1] == '\0'))
		{
			parse->token->files = ft_get_files(&str[i]);
			break ;
		}
		else if (str[i] == ' ' && str[i + 1] != '-')
		{
			parse->token->files = ft_get_files(&str[++i]);
			break ;
		}
		flag[j++] = str[i++];
	}
	if (str[0] == '\0')
		return (NULL);
	flag[j] = '\0';
	return (flag);
}

char	*ft_get_cmd(char *str)
{
	char	*cmd;
	int		i;
	int		j;

	cmd = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		cmd[j] = str[i];
		i++;
		j++;
	}
	if (str[0] == '\0')
		return (NULL);
	cmd[j] = '\0';
	return (cmd);
}
