/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:19:32 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/03 17:19:34 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*get_envp_path(t_env **env_list)
{
	char	*envp_path;

	envp_path = NULL;
	while ((*env_list)->next != NULL)
	{
		if (get_builtin((*env_list)->str, "PATH") == 0)
		{
			envp_path = ft_strdup((*env_list)->value);
			break ;
		}
		(*env_list) = (*env_list)->next;
	}
	return (envp_path);
}

char	*get_value(t_env **env_list, char *str)
{
	char	*envp_path;

	envp_path = NULL;
	while ((*env_list)->next != NULL)
	{
		if (get_builtin((*env_list)->str, str + 1) == 0)
		{
			envp_path = ft_strdup((*env_list)->value);
			break ;
		}
		(*env_list) = (*env_list)->next;
	}
	if (get_builtin((*env_list)->str, str + 1) == 0)
		envp_path = ft_strdup((*env_list)->value);
	return (envp_path);
}
