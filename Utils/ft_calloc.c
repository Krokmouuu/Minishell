/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:40:16 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/08 17:40:32 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	c = malloc(size * count);
	if (c == NULL)
		return (NULL);
	while (i < size * count)
		c[i++] = '\0';
	return ((void *)c);
}