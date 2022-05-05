/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/04 16:59:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_function(int sig)
{
	if (sig == 0)
		printf("sig = 0\n");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

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
		free_list(&list);
	}
	return (0);
}
