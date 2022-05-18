/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:51:26 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:04 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	pwd_command(t_token **blist, t_env **env)
{
	t_env	*read;
	char	*pwd;

	if ((*blist)->next->next != NULL)
	{
		g_struct.exit_status = 1;
		printf("pwd: too many arguments\n");
		return (0);
	}
	pwd = getcwd(NULL, 0);
	read = (*env);
	printf("%s\n", pwd);
	free(pwd);
	g_struct.exit_status = 0;
	return (0);
}
