/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:33:49 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/18 10:56:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	redirect_in(t_token *read)
{
	int	fd;

	read = read->next;
	fd = open(read->args, O_RDONLY);
	if (fd == -1)
		return (50);
	dup2(fd, 0);
	close(fd);
	return (1);
}

int	redirect_out(t_token *read, int i)
{
	int	fd;

	read = read->next;
	if (i == 0)
	{
		fd = open(read->args, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd == -1)
			return (50);
	}
	else
	{
		fd = open(read->args, O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (fd == -1)
			return (50);
	}
	dup2(fd, 1);
	close(fd);
	return (1);
}

int	checklist(t_token **list)
{
	int		i;
	char	*str;	
	t_token	*temp;

	temp = (*list);
	i = 0;
	while (temp->next != NULL)
	{
		if (temp->type == 0 || temp->type == 1)
		{
			str = temp->args;
			if (ft_strlen(str) > 1)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_token	*new_list(t_token **blist, t_token **newlist)
{
	t_token	*temp;
	t_token	*temp_newlist;

	temp_newlist = (*newlist);
	temp = (*blist);
	while (temp->next != NULL)
	{
		if ((temp->type == FILE_IN || temp->type == FILE_OUT
				|| temp->type == APPEND)
			&& temp->quoted <= 0)
			temp = temp->next->next;
		else if (temp->type == HERE && temp->quoted <= 0)
			temp = temp->next;
		else
		{
			temp_newlist->args = ft_strdup(temp->args);
			temp_newlist->type = temp->type;
			ft_lstadd_back(temp_newlist);
			temp_newlist = temp_newlist->next;
			temp = temp->next;
		}
	}
	return (temp_newlist);
}

int	checkredirection(t_token **blist, int *save_fd)
{
	t_token	*read;
	int		i;

	i = 0;
	read = (*blist);
	while (read->next != NULL)
	{
		if (!read->next)
			break ;
		if (read->type == FILE_OUT && read->next->type == FILE_OUT)
			return (50);
		if (read->type == FILE_IN && read->next->type == -1
			&& read->quoted != 2 && read->quoted != 1)
			i += redirect_in(read);
		else if (read->type == FILE_OUT && read->next->type == -1
			&& read->quoted != 2 && read->quoted != 1)
			i += redirect_out(read, 0);
		else if (read->type == APPEND && read->next->type == -1
			&& read->quoted != 2 && read->quoted != 1)
			i += redirect_out(read, 1);
		else if (read->type == HERE && read->quoted != 2 && read->quoted != 1)
			i += prompt_here_doc(read, save_fd);
		read = read->next;
	}
	return (i);
}
