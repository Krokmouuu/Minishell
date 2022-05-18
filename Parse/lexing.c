/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/18 10:58:42 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	attribtoken(char *str, int quoted)
{
	int	i;

	i = 0;
	if (str[i] == '<' && str[i + 1] == '<' && quoted != 2 && quoted != 1)
		return (HERE);
	else if (str[i] == '>' && str[i + 1] == '>' && quoted != 2 && quoted != 1)
		return (APPEND);
	else if (str[i] == '>' && quoted != 2 && quoted != 1)
		return (FILE_OUT);
	else if (str[i] == '-' && str[i + 1] > 32 && str[i + 1] < 127)
		return (FLAGS);
	else if (str[i] == '<' && quoted != 2 && quoted != 1)
		return (FILE_IN);
	else if (str[i] == '|' && quoted != 2 && quoted != 1)
		return (PIPES);
	else if (str[i] == '$' && quoted != 1)
		return (DOLLARS);
	else if (str[i] == '?')
		return (QUESTION_MARK);
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

void	savefd(int *save_fd)
{
	save_fd[0] = dup(STDIN_FILENO);
	save_fd[1] = dup(STDOUT_FILENO);
}

int	restorefd(int *save_fd)
{
	dup2(save_fd[0], STDIN_FILENO);
	close(save_fd[0]);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[1]);
	return (0);
}

int	lexing(t_token **blist, char *str)
{
	char	*uwu;

	uwu = remove_spaces(str);
	if (validquote(uwu, 2147483647))
		return (validquotebrother(uwu, str, 1));
	ft_split_all(blist, uwu);
	tokenizer(blist);
	validquotebrother(uwu, str, 0);
	if (get_builtin((*blist)->args, "$?") == 0)
		return (errorcmd3(0));
	return (0);
}
