/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:51:39 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/17 14:26:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*ft_find(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			while (env[i][j] == str[j])
				j++;
			if (str[j] == '\0')
				return (env[i]);
			else
				break ;
		}
		i++;
	}
	return (NULL);
}

int	ft_findspace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

int	is_letter(char c)
{
	if (c < 33 || c > 126)
		return (1);
	return (0);
}

int	get_builtin(char *str, char *cmd)
{
	int	i;
	int	end;

	i = 0;
	if (!str)
		return (-1);
	end = ft_strlen(cmd);
	while (cmd[i])
	{
		if (cmd[i] != str[i])
			return (-1);
		i++;
	}
	if (ft_strlen(str) > ft_strlen(cmd))
		return (-1);
	return (0);
}

int	builtins(t_token **blist, t_env **env_list, int toto)
{
	t_token	*read;
	char	*pwd;

	read = (*blist);
	pwd = NULL;
	if (get_builtin(read->args, "pwd") == 0)
		return (pwd_command(blist, env_list));
	if (get_builtin(read->args, "env") == 0)
		return (print_list_env(env_list));
	if (get_builtin(read->args, "export") == 0)
		return (export_command(blist, env_list));
	if (get_builtin(read->args, "unset") == 0)
		return (unset_command(blist, env_list));
	if (get_builtin(read->args, "echo") == 0 && toto == 2)
		return (echo_command_redirect(blist, env_list));
	else if (get_builtin(read->args, "echo") == 0)
		return (echo_command(blist, env_list));
	if (get_builtin(read->args, "cd") == 0)
		return (cd_command(blist, env_list));
	if (get_builtin(read->args, "exit") == 0)
		return (exit_command(blist));
	return (-1);
}
