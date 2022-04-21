/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:51:26 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/14 11:51:28 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd_command(char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	pwd = ft_substr(ft_find(env, "PWD="), 5, \
		ft_findspace(ft_find(env, "PWD=")) - 4);
	printf("%s\n", pwd);
	free(pwd);
}
