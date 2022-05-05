/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:48:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 16:12:02 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt_here_doc(t_token **blist, t_token *read)
{
	char	*str;

	(void)blist;
	while (1)
	{
		str = readline("Ici Doc > ");
		if (get_builtin(read->args + 2, str) == 0)
			return (0);
	}
	return (1);
}

int	errorcmd2(char *str, int i, int *fd)
{
	restorefd(fd);
	if (i == 1)
		printf("minishell: %s: No such file or directory\n", str);
	else if (i == 2)
		printf("minishell: %s: command not found\n", str);
	else if (i == 3)
		printf("exit\nminishell: exit: %s: numeric argument required\n", str);
	else if (i == 4)
		printf("syntax error near unexpected token %s\n", str);
	return (0);
}

void	errorcmd(char *str, int i)
{
	if (i == 1)
		printf("minishell: %s: No such file or directory\n", str);
	else if (i == 2)
		printf("minishell: %s: command not found\n", str);
	else if (i == 3)
		printf("exit\nminishell: exit: %s: numeric argument required\n", str);
	else if (i == 4)
		printf("syntax error near unexpected token %s\n", str);
	exit(-1);
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
	str = readline("Minishell$ 🥵🍆🐇📨 🥖> ");
	while (str && str[++i])
		if (str && str[i] == '<' && str[i + 1] == '<')
			j++;
	if (str && j == 0 && str[0] != '\0')
		add_history(str);
	return (str);
}
