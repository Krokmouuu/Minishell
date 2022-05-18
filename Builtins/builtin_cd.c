/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:14 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/04 14:38:52 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	cd_command(t_token **blist, t_env **env_list)
{
	char	*str;
	char	*get;
	t_token	*read;

	read = (*blist);
	get = getcwd(NULL, 0);
	str = ft_strjoin("OLDPWD=", get);
	ft_lstadd_back_export(env_list, str, 1);
	free(str);
	free(get);
	if (chdir(read->next->args) != 0)
	{
		g_struct.exit_status = 1;
		if (!read->next->args)
			return (0);
		errorcmd(read->next->args, 5);
		return (0);
	}
	get = getcwd(NULL, 0);
	str = ft_strjoin("PWD=", get);
	ft_lstadd_back_export(env_list, str, 1);
	free(str);
	free(get);
	g_struct.exit_status = 0;
	return (0);
}
