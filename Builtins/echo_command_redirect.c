/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command_redirect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:41:47 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 17:02:39 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	echo_command_redirect(t_token **blist, t_env **t_env_list)
{
	int		ndash;
	int		i;
	t_token	*read;

	read = (*blist);
	i = 0;
	ndash = 0;
	read = read->next;
	while (read->type == 9 && read->next != NULL)
	{
		if (ft_check_nflag(&read, i) > 0)
			ndash = 1;
		else
		{
			read = read->next;
			break ;
		}
		read = read->next;
	}
	echo_avatar_two(read, t_env_list);
	printf("\n");
	return (0);
}
