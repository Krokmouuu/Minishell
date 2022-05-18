/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:12:41 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/16 13:14:23 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	redirect(t_token **blist, t_env **env_list, char **env)
{
	int		save_fd[2];
	t_token	*newlist;
	t_token	**bnewlist;
	int		i;

	newlist = NULL;
	bnewlist = &newlist;
	init_list(bnewlist);
	savefd(save_fd);
	i = checkredirection(blist, save_fd);
	if (i != 0)
	{
		if (checklist(blist) == 0 || i >= 50)
			return (errorcmd2(NULL, 5, save_fd));
		new_list(blist, bnewlist);
		if (builtins(bnewlist, env_list, 2) != 0)
			exec_cmd2(bnewlist, env_list, env, save_fd);
	}
	else
		if (builtins(blist, env_list, 0) != 0)
			exec_cmd(blist, env_list, env);
	free_list(&newlist);
	restorefd(save_fd);
	return (1);
}
