/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:28 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/07 18:25:33 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**args(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(*str) + 1) * sizeof(char *));
	while (str[i][j])
	{
		if ()
		i++;
	}
	return (str);
}

char	**splitinput(t_parse *parse)
{
	int		i;
	char	**str;
	int		j;

	j = 0;
	i = 0;
	str = &parse->input;
	while (str[i][j] == ' ' || str[i][j] == '\t'
	|| str[i][j] == '\n')
		j++;
	parse->cmdsplit = args(str);
	i = 0;
	while (i < 20)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (str);
}
