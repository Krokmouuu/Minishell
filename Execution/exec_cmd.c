/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:15 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:55:22 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	exec_cmd(t_token **blist, t_env **env_list, char **env)
{
	t_token	*list;
	t_env	*t_env;

	list = (*blist);
	t_env = (*env_list);
	(void)env;
	return (0);
}
