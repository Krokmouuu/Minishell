/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 18:15:37 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{	
	char	*str;
	t_token	*list;
	t_token	**blist;

	list = NULL;
	(void)argc;
	(void)argv;
	blist = &list;
	while (1)
	{
		init_list(blist);
		str = input();
		if (str == NULL)
			exitshell(blist);
		lexing(blist, str, env);
		ft_list_length(blist);
		free_list(&list);
	}
	return (0);
}
