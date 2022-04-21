/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:48:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/19 15:39:22 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	errorcmd(char *str)
{
	printf("%s\n", str);
}

void	exitshell(t_token **blist)
{
	(void)blist;
	exit (0);
}

char	*input(void)
{
	char	*str;

	str = readline("Minishell$ 🥵🍆🐇 > ");
	if (str == NULL)
		return (NULL);
	if (str[0] != '\0')
		add_history(str);
	return (str);
}
