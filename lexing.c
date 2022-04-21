/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:53:09 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 19:36:02 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	int		n;
	char	*cmd;

	j = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	n = i;
	while (str[i] != '\0')
		i++;
	cmd = ft_calloc(i + 1, 1);
	while (str[n] != '\0')
		cmd[j++] = str[n++];
	cmd[j] = '\0';
	return (cmd);
}

void	splitpipe(t_token **blist, char *str)
{
	int		i;
	int		n;
	t_token	*temp;

	n = 0;
	i = 0;
	temp = (*blist);
	str = remove_spaces(str);
	while (str[i])
	{
		if (str[i] != '|' || str[i] != '\0')
			i++;
		if (str[i] == '|' || str[i] == '\0')
		{
			temp->cmd = ft_substr(str, n, i - n);
			temp->type = 1;
			ft_lstadd_back(temp);
			temp = temp->next;
			if (str[i] == '\0')
				break ;
			n = i + 1;
		}
	}
	free(str);
}

void	lexing(t_token **blist, char *str, char **env)
{
	char	*uwu;

	uwu = remove_spaces(str);
	ft_split_all(blist, uwu);
	builtins(blist, env);
	(void)env;
	free (str);
	free (uwu);
}
