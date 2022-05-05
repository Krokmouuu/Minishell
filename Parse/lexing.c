/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 19:27:01 by bleroy           ###   ########.fr       */
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
			return (HERE_DOC);
		else if (str[i] == '>' && str[i + 1] == '>')
			return (APPEND);
		else if (str[i] == '>')
			return (FILE_OUT);
		else if (str[i] == '-' && str[i + 1] > 32 && str[i + 1] < 127)
			return (FLAGS);
		else if (str[i] == '<')
			return (FILE_IN);
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

void	tokenizer(t_token **blist, int *save_fd)
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
	savefd(save_fd);
}

void	savefd(int *save_fd)
{
	save_fd[0] = dup(STDIN_FILENO);
	save_fd[1] = dup(STDOUT_FILENO);
}

void	restorefd(int *save_fd)
{
	dup2(save_fd[0], STDIN_FILENO);
	close(save_fd[0]);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[1]);
}

int	lexing(t_token **blist, char *str, t_env **env_list, char **env)
{
	char	*uwu;
	int		save_fd[2];
	t_token	*newlist;
	t_token	**bnewlist;

	newlist = NULL;
	bnewlist = &newlist;
	init_list(bnewlist);
	uwu = remove_spaces(str);
	if (validquote(uwu, 2147483647))
		return (validquotebrother(uwu, str, 1));
	ft_split_all(blist, uwu);
	tokenizer(blist, save_fd);
	if (checkredirection(blist) != 0)
	{
		new_list(blist, bnewlist);
		if (builtins(bnewlist, env_list, 2) != 0)
			exec_cmd2(bnewlist, env_list, env, save_fd);
	}
	else if (builtins(blist, env_list, 0) != 0)
		exec_cmd(blist, env_list, env);
	validquotebrother(uwu, str, 0);
	free_list(&newlist);
	restorefd(save_fd);
	return (0);
}
