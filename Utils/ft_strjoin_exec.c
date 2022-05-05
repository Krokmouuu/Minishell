/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:52:36 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/02 12:52:42 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

char	*ft_strjoin_exec(char const *s1, char const *s2, int n)
{
	int		i;
	char	*str;

	i = 0;
	i = ft_strlen(s1);
	n = ft_strlen(s2);
	str = malloc((i + n) + 2 * sizeof(char));
	if (str == NULL || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	n = 0;
	while (s2[n])
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = '\0';
	return (str);
}
