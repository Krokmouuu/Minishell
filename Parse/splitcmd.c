/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:31:44 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/16 19:02:51 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	specialk(char *str)
{
	int	i;

	i = 2;
	while (str[i] && ft_strlen(str) >= 3)
	{
		if (str[i] == SQUOTE || str[i] == DQUOTE)
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_cmd(t_token *blist, char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (specialk(str) == 1)
	{
		g_struct.doublequote = 1;
		return (1);
	}
	else if (str[i] == DQUOTE)
		j = double_quote(blist, str);
	else if (str[i] == SQUOTE)
		j = single_quote(blist, str);
	return (j);
}

void	ft_split_all(t_token **blist, char *str)
{
	t_token	*temp;
	int		i;
	int		len;

	i = 0;
	temp = (*blist);
	while (str && str[i])
	{
		i += whitespace(&str[i]);
		if ((str[i] == ' ' && str[i + 1] == '\0') || str[i] == '\0')
			break ;
		if (str[i] == DQUOTE || str[i] == SQUOTE)
			len = ft_get_cmd(temp, &str[i++]);
		else if (str[i] != DQUOTE || str[i] != SQUOTE)
		{
			len = lenword(&str[i]);
			temp->args = ft_strdup_len(&str[i], len);
		}
		if (len > 0 && g_struct.doublequote == 0)
		{
			ft_lstadd_back(temp);
			temp = temp->next;
		}
		i += len;
	}
}
