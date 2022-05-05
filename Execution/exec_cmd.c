/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:15 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 14:58:07 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

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

void	ft_execve(t_token **list, t_env **env_list, char **env)
{
	char	*envp_path;
	char	*path;
	char	**new_path;
	char	**arguments;
	int		i;

	i = 0;
	envp_path = get_envp_path(env_list);
	new_path = ft_split(envp_path, ':');
	arguments = ft_get_args(list, env_list);
	if ((*list)->args == NULL)
		exit(-1);
	if (!new_path)
		errorcmd((*list)->args, 1);
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
	errorcmd((*list)->args, 2);
}

// GERER $ls COMMANDE DANS VARIABLE D'ENVIRONNEMENT
void	process_one(t_token **list, t_env **env_list, char **env)
{
	ft_execve(list, env_list, env);
}

int	exec_cmd(t_token **blist, t_env **env_list, char **env)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == 0)
		process_one(blist, env_list, env);
	waitpid(pid1, NULL, 0);
	return (0);
}
