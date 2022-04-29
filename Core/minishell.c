/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/28 15:14:14 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{	
	char	*str;
	t_token	*list;
	t_token	**blist;
	t_env	*env_list;
	t_env	**real_env;

	env_list = NULL;
	real_env = &env_list;
	list = NULL;
	(void)argc;
	(void)argv;
	blist = &list;
	env_command(real_env, env);
	while (1)
	{
		init_list(blist);
		str = input();
		if (str == NULL)
			exitshell(blist);
		lexing(blist, str, real_env, env);
		//ft_list_length(blist);
		free_list(&list);
	}
	return (0);
}
