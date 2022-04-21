/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:51:39 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/21 15:40:22 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			while (env[i][j] == str[j])
				j++;
			if (str[j] == '\0')
				return (env[i]);
			else
				break ;
		}
		i++;
	}
	return (NULL);
}

int	ft_findspace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}
// -4 pour enlever les char parasites en bout de ligne

int	is_letter(char c)
{
	if (c < 33 || c > 126)
		return (1);
	return (0);
}

int	get_builtin(char *str, char *cmd)
{
	int	i;
	int	end;

	i = 0;
	if (!str)
		return (-1);
	end = ft_strlen(cmd);
	while (cmd[i])
	{
		if (cmd[i] != str[i])
			return (-1);
		i++;
	}
	if (ft_strlen(str) > ft_strlen(cmd))
		return (-1);
	return (0);
}

void	builtins(t_token **blist, char **env)
{
	t_token	*read;
	char	*pwd;
	int		i;

	read = (*blist);
	pwd = NULL;
	i = 0;
	(void)env;
	if (get_builtin(read->cmd, "pwd") == 0)
		pwd_command(env);
	if (get_builtin(read->cmd, "env") == 0)
		env_command(env);
	if (get_builtin(read->cmd, "echo") == 0)
		echo_command(blist);
}
