/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:03:03 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 19:27:14 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	validquotebrother(char *uwu, char *owo, int i)
{
	if (i == 1)
	{
		printf("Missing Quote\n");
		free (uwu);
		free (owo);
		return (0);
	}
	free (uwu);
	free (owo);
	return (0);
}

// void	redirectiontime(t_token	**b, t_token **n, t_env **el, char **e, int *f)
// {
// 	new_list(b, n);
// 	if (builtins(n, el, 2) != 0)
// 		exec_cmd2(n, el, e, f);
// }
