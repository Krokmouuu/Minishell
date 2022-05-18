/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/18 15:54:53 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global		g_struct;

void	reset_global(void)
{
	g_struct.f = 0;
	g_struct.h = 0;
	signal(SIGINT, signal_function);
	signal(SIGQUIT, signal_function);
}

void	heredoc_stopper(int sig)
{
	if (sig == 2)
	{
		g_struct.exit_status = 130;
		rl_on_new_line();
		rl_redisplay();
		printf("  \n");
		rl_replace_line("", 0);
		exit(130);
	}
	if (sig == 3)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_function(int sig)
{
	if (sig == 2 && g_struct.f == 0)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == 2 && g_struct.f != 0)
	{
		printf("  \n");
		rl_on_new_line();
	}
	else if (sig == 3 && g_struct.f == 0)
	{
		printf("\033[0J");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == 3 && g_struct.f != 0)
	{
		printf("Quit: 3\n");
		rl_on_new_line();
	}
}

int	setup(int argc, char **argv, char **env, t_env **real_env)
{
	(void)argc;
	(void)argv;
	env_command(real_env, env);
	g_struct.f = 0;
	g_struct.h = 0;
	g_struct.exit_status = 0;
	g_struct.id = getpid();
	g_struct.doublequote = 0;
	return (0);
}

int	main(int argc, char **argv, char **env)
{	
	char	*str;
	t_token	*list;
	t_token	**blist;
	t_env	*env_list;
	t_env	**real_env;

	env_list = NULL;
	list = NULL;
	real_env = &env_list;
	blist = &list;
	setup(argc, argv, env, real_env);
	while (1)
	{
		init_list(blist);
		str = input();
		if (str == NULL)
			exitshell(blist);
		if (lexing(blist, str) == 0)
			redirect(blist, &env_list, env);
		free_list(&list);
		if (g_struct.id != getpid() && (g_struct.f == 1 || g_struct.h == 1))
			kill(getpid(), SIGKILL);
		reset_global();
	}
	return (0);
}
