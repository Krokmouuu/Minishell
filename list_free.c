/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:57:05 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/14 14:18:15 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//New set of functions to free lists which works but only frees cmd

void	list_free_data(void *data)
{
	free(data);
}

void	*list_shift(t_token **blist)
{
	t_token		*del;
	void		*data;

	del = (*blist);
	data = del->cmd;
	if ((*blist)->next)
		*blist = (*blist)->next;
	else
		*blist = NULL;
	free(del);
	return (data);
}

void	list_clear(t_token **blist, void (*free_data)(void *data))
{
	while (*blist)
		(*free_data)(list_shift(blist));
}
