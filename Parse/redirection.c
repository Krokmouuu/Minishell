/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:33:49 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 19:35:34 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	redirect_in(t_token *read)
{
	int	fd;

	read = read->next;
	fd = open(read->args, O_RDONLY | O_CREAT);
	if (fd == -1)
		printf("REDIRECT IN ERROR MESSAGE TO SET UP");
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
			printf("REDIRECT OUT TRUNC ERROR MESSAGE TO SET UP");
	}
	else
	{
		fd = open(read->args, O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (fd == -1)
			printf("REDIRECT OUT APPEND ERROR MESSAGE TO SET UP");
	}
	dup2(fd, 1);
	close(fd);
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
				|| temp->type == APPEND || temp->type == HERE_DOC)
			&& temp->quoted <= 0)
		{
			if (ft_list_length(blist) <= 3)
				return (NULL);
			temp = temp->next->next;
		}
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

int	checkredirection(t_token **blist)
{
	t_token	*read;
	int		i;

	i = 0;
	read = (*blist);
	while (read->next != NULL)
	{
		if (!read->next)
			break ;
		if (read->type == FILE_IN && read->next->type == -1)
			i += redirect_in(read);
		else if (read->type == FILE_OUT && read->next->type == -1)
			i += redirect_out(read, 0);
		else if (read->type == APPEND && read->next->type == -1)
			i += redirect_out(read, 1);
		else if (read->type == HERE_DOC && read->next->type == -1)
			i += prompt_here_doc(blist, read);
		read = read->next;
	}
	return (i);
}
