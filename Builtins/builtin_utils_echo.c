/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils_echo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:46:07 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:10 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	max(char **flags)
{
	int	i;

	i = 0;
	while (flags[i])
		i++;
	return (i);
}

int	ft_return_echo(int mama, int max, int check)
{
	if (mama == 0)
		return (max);
	return (check);
}

void	print_line(int check, char **flags, int i, int n)
{
	if (check > 0)
		printf("%s", flags[i]);
	if ((check > 0 && flags[i][n - 1] == 'n') ||
			(flags[i][n - 1] != 'n' && i + 1 < max(flags) && check >= 0))
		printf(" ");
}
