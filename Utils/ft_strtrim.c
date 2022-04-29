/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:47:01 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:56:04 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

static char	verif(char c, char set)
{
	printf("%c\n", c);
	if (c == set)
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char set)
{
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (verif(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		newstr = ft_strdup("");
		if (newstr == NULL)
			return (NULL);
		else
			return (newstr);
	}
	while (verif(s1[end - 1], set) == 0)
		end--;
	newstr = ft_substr(s1, start, end - start);
	return (newstr);
}
