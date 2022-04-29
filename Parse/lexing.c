/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:55:25 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	attribtoken(char *str, int quoted)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
			return (SHIFT_LEFT);
		else if (str[i] == '>' && str[i + 1] == '>')
			return (SHIFT_RIGHT);
		else if (str[i] == '>')
			return (FILE_IN);
		else if (str[i] == '-' && str[i + 1] > 32 && str[i + 1] < 127)
			return (FLAGS);
		else if (str[i] == '<')
			return (FILE_OUT);
		else if (str[i] == '|')
			return (PIPES);
		else if (str[i] == '$' && quoted != 1)
			return (DOLLARS);
		else if (str[i] == '?')
			return (QUESTION_MARK);
		i++;
	}
	return (-1);
}

void	tokenizer(t_token **blist)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = (*blist);
	while (temp->next != NULL)
	{
		temp->type = attribtoken(temp->args, temp->quoted);
		temp = temp->next;
	}
}

void	lexing(t_token **blist, char *str, t_env **env_list, char **env)
{
	char	*uwu;

	(void)env;
	(void)env_list;
	uwu = remove_spaces(str);
	if (validquote(uwu, 2147483647))
	{
		errorcmd("Missing Quote");
		free (uwu);
		free (str);
		return ;
	}
	ft_split_all(blist, uwu);
	tokenizer(blist);
	if (builtins(blist, env_list) != 0)
		exec_cmd(blist, env_list, env);
	free (str);
	free (uwu);
}
