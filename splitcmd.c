/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:31:44 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 20:00:15 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*skip(char *str)
{
	int	i;
	int	j;

	i = helperspace(str, 0);
	j = i;
	if (str[i] == '\0')
		return (ft_strdup(""));
	else if (str[i] != '-' || (str[i] == '-' && str[i + 1] == '\0'))
		return (ft_strdup(&str[i]));
	else
	{
		while (str[i])
		{
			while (str[i] != ' ' && str[i])
				i++;
			while (str[i] == ' ' && str[i])
				i++;
			if (str[i] == '-' && str[i])
				i++;
			else
				return (ft_strdup(&str[i]));
		}
	}
	return (NULL);
}

char	*ft_get_args(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '|' && str[i] != '\0')
		i++;
	return (ft_substr(str, j, i - j));
}

char	*ft_get_flags(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = i;
	if ((str[i] == '-' && str[i + 1] == '\0')
		|| (str[i] == '-' && str[i + 1] == ' '))
		return (NULL);
	if (str[i] != '-' || str[i] == '\0')
		return (NULL);
	while (str[i])
	{
		i += helperspace(&str[i], 1);
		if (str[i] != '-' || str[i] == '\0')
			return (ft_substr(str, j, i - j));
		if ((str[i] == '-' && str[i + 1] == ' ')
			|| (str[i] == '-' && str[i + 1] == '\0'))
			return (ft_substr(str, j, i - j));
		i += helperspace(&str[i], 2);
		if (str[i] == '\0')
			return (ft_substr(str, j, i - j));
	}
	return (0);
}

char	*ft_get_cmd(char *str)
{
	int		i;
	int		j;
	char	*test;

	test = ft_calloc(lenwithoutquote(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] == 34)
			while (str[i++] != 34 && str[i++])
				test[j++] = str[i];
		else if (str[i] == 39)
			while (str[i++] != 39 && str[i++])
				test[j++] = str[i];
		else if (str[i] != 34 && str[i] != 39)
			test[j++] = str[i++];
	}
	test[j] = '\0';
	return (test);
}

void	ft_split_all(t_token **blist, char *str)
{
	t_token	*temp;

	temp = (*blist);
//	if (!validquote(str))
	temp->cmd = ft_get_cmd(str);
	str = skip2(str);
	printf("Oh shit -> %s\n", str);
	temp->flags = ft_get_flags(str);
	// str = skip(str);
	// temp->args = ft_get_args(str);
	//free(str);
}
