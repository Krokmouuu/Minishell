/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:20:41 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:55:39 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*ft_strdup_len(const char *c, int len)
{
	int		i;
	char	*str;

	i = 0;
	while (c[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (c[i] && i < len)
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
