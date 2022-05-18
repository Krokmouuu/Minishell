/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:30:53 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/17 18:26:43 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global		g_struct;

int	errorcmd2(char *str, int i, int *fd)
{
	restorefd(fd);
	if (i == 1)
	{
		g_struct.exit_status = 1;
		printf("minishell: %s: No such file or directory\n", str);
	}
	else if (i == 2)
	{
		g_struct.exit_status = 127;
		printf("minishell: %s: command not found\n", str);
	}
	else if (i == 3)
		printf("exit\nminishell: exit: %s: numeric argument required\n", str);
	else if (i == 4)
		printf("syntax error near unexpected token %s\n", str);
	else if (i == 5)
		printf("file or syntax error\n");
	return (0);
}

int	errorcmd3(int i)
{
	if (i == 0)
	{
		printf("minishell: %d: command not found\n", g_struct.exit_status);
		g_struct.exit_status = 127;
	}
	return (5);
}

void	errorcmd(char *str, int i)
{
	if (i == 1)
	{
		g_struct.exit_status = 1;
		printf("minishell: %s: No such file or directory\n", str);
	}
	else if (i == 2)
	{
		g_struct.exit_status = 127;
		printf("minishell: %s: command not found\n", str);
	}
	else if (i == 3)
		printf("exit\nminishell: exit: %s: numeric argument required\n", str);
	else if (i == 4)
	{
		g_struct.exit_status = 2;
		printf("syntax error near unexpected token %s\n", str);
	}
	if (i == 5)
	{
		g_struct.exit_status = 1;
		printf("minishell: cd: %s: No such file or directory\n", str);
	}
	exit(g_struct.exit_status);
}
