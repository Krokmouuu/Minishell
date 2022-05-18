/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:20:41 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/16 18:26:42 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*ft_strdup_len(const char *c, int len)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while (c[i])
		i++;
	str = ft_calloc(i, sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (c[i] && i < len)
	{
		if (c[i] == DQUOTE || c[i] == SQUOTE)
			i++;
		else
			str[j++] = c[i++];
	}
	str[i] = '\0';
	return (str);
}
