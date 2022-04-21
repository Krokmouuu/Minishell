/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:52:40 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 19:18:35 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	tmp = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i] != '\0')
			tmp[i] = str[i];
	j = 0;
	while (buf[j] != '\0')
		tmp[i++] = buf[j++];
	tmp[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free (str);
	return (tmp);
}
