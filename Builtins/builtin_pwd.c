/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:51:26 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:04 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	pwd_command(t_env **env)
{
	int		i;
	char	*path;
	t_env	*read;

	i = 0;
	path = NULL;
	read = (*env);
	read = read->next;
	while (read->next)
	{
		i = 0;
		if (read->str[i] == 'P' && read->str != NULL)
		{
			i++;
			if (read->str[i] == 'W')
			{
				i++;
				if (read->str[i] == 'D')
					return (printf("%s\n", read->value));
			}
		}
		read = read->next;
	}
	return (0);
}
