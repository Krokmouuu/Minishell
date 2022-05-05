/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:53:22 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/05 14:57:01 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

//Tout free, ne pas accepter plusieurs arguments, demander un int en argument
int	exit_command(t_token **blist)
{
	t_token	*read;
	int		i;

	read = (*blist);
	i = -1;
	if (read->next != NULL)
	{
		read = read->next;
		if (read->args != NULL)
		{
			while (read->args[++i])
			{
				if (read->args[i] < '0' || read->args[i] > '9')
					errorcmd(read->args, 3);
			}
		}
	}
	if (ft_list_length(blist) > 3)
		printf("exit\nminishell: exit: too many arguments\n");
	else
		printf("exit\n");
	exit(0);
}
