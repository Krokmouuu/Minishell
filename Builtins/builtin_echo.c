/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:50:42 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/20 18:18:43 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_max(char **flags)
{
	int	i;

	i = 0;
	while (flags[i])
		i++;
	return (i);
}

int	ft_print_flag(char **flags, int i, t_token **blist)
{
	int	check;
	int	n;
	int	max;
	int	mama;

	check = 0;
	mama = 1;
	max = ft_get_max(flags);
	while (flags[i])
	{
		n = 1;
		while (flags[i][n])
		{
			if (flags[i][n] != 'n' && flags[i][n] != '\0')
			{
				check++;
				break ;
			}
			if (check >= i && i > 0)
				mama = 0;
			n++;
		}
		if (check > 0)
			printf("%s", flags[i]);
		if (check > 0 && flags[i][n - 1] == 'n')
			printf(" ");
		if (flags[i][n - 1] != 'n' && i + 1 < max && check >= 0)
			printf(" ");
		i++;
	}
	if (flags[i - 1][n - 1] != 'n' && (*blist)->args != NULL)
		printf(" ");
	if (mama == 0)
		return (max);
	return (check);
}

int	ft_check_nflag(t_token **blist, int i)
{
	int		n;
	int		check;
	char	**flags;

	n = 0;
	check = 0;
	if (!(*blist)->flags)
		return (-1);
	if ((*blist)->flags[i + 1] == '-' || ft_strlen((*blist)->flags) < 2)
	{
		printf("%s", (*blist)->flags);
		return (-1);
	}
	flags = ft_split((*blist)->flags, ' ');
	check = ft_print_flag(flags, i, blist);
	while (flags[i])
		free(flags[i++]);
	free (flags);
	flags = NULL;
	if (check < i)
		return (1);
	return (0);
}

void	echo_command(t_token **blist)
{
	int	ndash;
	int	i;

	i = 0;
	ndash = 0;
	if (ft_check_nflag(blist, i) > 0)
		ndash = 1;
	if ((*blist)->args != NULL)
		printf("%s", (*blist)->args);
	if (ndash == 0)
		printf("\n");
}
