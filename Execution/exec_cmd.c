/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:15 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/09 12:05:24 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

t_global		g_struct;

char	**ft_get_args(t_token **list, t_env **env_list)
{
	int		i;
	char	**arguments;
	t_token	*read;

	read = (*list);
	i = 0;
	arguments = ft_calloc(1000, 1000);
	while (read->next != NULL)
	{
		if (read != NULL)
		{
			if (read->type == 7)
				arguments[i] = get_value(env_list, read->args);
			else
				arguments[i] = ft_strdup(read->args);
		}
		i++;
		read = read->next;
	}
	return (arguments);
}

char	*get_env_command(t_token **list, t_env **env_list)
{
	char	*path;
	t_token	*read;

	read = (*list);
	if (read->type == 7)
		path = get_value(env_list, read->args);
	else
		path = ft_strdup(read->args);
	return (path);
}

void	ft_execve(t_token **list, t_env **env_list, char **env)
{
	char	*str;
	char	*path;
	char	**new_path;
	char	**arguments;
	int		i;

	i = -1;
	str = get_envp_path(env_list);
	new_path = ft_split(str, ':');
	arguments = ft_get_args(list, env_list);
	if ((*list)->args == NULL)
		exit(-1);
	if (!new_path)
		errorcmd((*list)->args, 1);
	free(str);
	str = get_env_command(list, env_list);
	while (new_path[++i] != NULL)
	{
		if (i == 0)
			execve(str, arguments, env);
		path = ft_strjoin_exec(new_path[i], str, 0);
		execve(path, arguments, env);
		free(path);
	}
	errorcmd((*list)->args, 2);
}

void	process_one(t_token **list, t_env **env_list, char **env)
{
	ft_execve(list, env_list, env);
}

int	exec_cmd(t_token **blist, t_env **env_list, char **env)
{
	pid_t	pid1;

	pid1 = fork();
	g_struct.f = 1;
	if (pid1 == 0)
		process_one(blist, env_list, env);
	waitpid(pid1, &g_struct.exit_status, 0);
	if (WIFEXITED(g_struct.exit_status))
		g_struct.exit_status = WEXITSTATUS(g_struct.exit_status);
	return (0);
}
