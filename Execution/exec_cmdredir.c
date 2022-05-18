/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdredir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:15 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/06 14:25:03 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	**ft_get_args2(t_token **list, t_env **env_list)
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

int	ft_execve2(t_token **list, t_env **env_list, char **env, int *fd)
{
	char	*envp_path;
	char	*path;
	char	**new_path;
	char	**arguments;
	int		i;

	i = 0;
	envp_path = get_envp_path(env_list);
	new_path = ft_split(envp_path, ':');
	arguments = ft_get_args2(list, env_list);
	if ((*list)->args == NULL)
		exit(-1);
	if (!new_path)
		return (errorcmd2((*list)->args, 1, fd));
	while (new_path[i] != NULL)
	{
		if (i == 0)
			path = ft_strdup((*list)->args);
		else
			path = ft_strjoin_exec(new_path[i], (*list)->args, 0);
		execve(path, arguments, env);
		free(path);
		i++;
	}
	return (errorcmd2((*list)->args, 2, fd));
}

void	process_one2(t_token **list, t_env **env_list, char **env, int *fd)
{
	ft_execve2(list, env_list, env, fd);
}

int	exec_cmd2(t_token **blist, t_env **env_list, char **env, int *fd)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
		process_one2(blist, env_list, env, fd);
	waitpid(pid1, NULL, 0);
	return (0);
}
