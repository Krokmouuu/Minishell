/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:03:14 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:08 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	unset_command(t_token **blist, t_env **env_list)
{
	t_env	*env;
	t_env	*temp_env;
	t_token	*list;

	env = (*env_list);
	list = (*blist);
	temp_env = env;
	if (list->next != NULL)
		list = list->next;
	while ((ft_strcmp(env->str, list->args) != 0) && env->next)
	{
		temp_env = env;
		env = env->next;
	}
	if (ft_strcmp(env->str, list->args) == 0)
	{
		temp_env->next = env->next;
		free(env->str);
		free(env->equal);
		free(env->value);
		free(env);
	}
	return (0);
}
