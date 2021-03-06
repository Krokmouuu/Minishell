/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:44:39 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/06 12:30:09 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	check_path(t_env **read)
{
	t_env	*list;

	list = (*read);
	while (list->next != NULL)
	{
		if (get_builtin(list->next->str, "PATH") == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

void	init_env(t_env **env_list)
{
	t_env	*list;

	list = malloc(sizeof(t_env));
	list->str = NULL;
	list->equal = NULL;
	list->value = NULL;
	list->next = (*env_list);
	*env_list = list;
}

void	fill_env_list(char **env, t_env **t_env_list)
{
	t_env	*list;
	int		i;

	list = (*t_env_list);
	i = 0;
	while (env[i])
	{
		ft_lstadd_back_env(t_env_list, env[i]);
		list = list->next;
		i++;
	}
}

void	env_command(t_env **env_list, char **env)
{
	t_env	*t_env_list;

	t_env_list = (*env_list);
	init_env(env_list);
	fill_env_list(env, env_list);
}
