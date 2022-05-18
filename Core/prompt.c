/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:48:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/09 12:02:10 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_function_hd(int sig)
{
	if (sig == 2)
		exit(1);
	if (sig == 3)
	{
		write(2, "Quit: 3\n", 8);
		rl_on_new_line();
		exit(1);
	}
}

void	exitshell(t_token **blist)
{
	(void)blist;
	exit (0);
}

char	*input(void)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	str = readline("Minishell$ 🥵🍆🐇📨🥖🤒🍾> ");
	while (str && str[++i])
		if (str && str[i] == '<' && str[i + 1] == '<')
			j++;
	if (str && j == 0 && str[0] != '\0')
		add_history(str);
	return (str);
}
