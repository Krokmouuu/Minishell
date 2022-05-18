/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils_echo_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:08:48 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/18 14:08:49 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

int	ft_print_flag(char **flags, int i, t_token **blist, int check)
{
	int	n;
	int	mama;

	mama = 1;
	while (flags[i])
	{
		n = 0;
		while (flags[i][++n])
		{
			if (flags[i][n] != 'n' && flags[i][n] != '\0')
			{
				check++;
				break ;
			}
			if (check >= i && i > 0)
				mama = 0;
		}
		print_line(check, flags, i, n);
		i++;
	}
	if (flags[i - 1][n - 1] != 'n' && (*blist)->next->args != NULL)
		printf(" ");
	return (ft_return_echo(mama, max(flags), check));
}

int	ft_check_nflag(t_token **blist, int i)
{
	int		n;
	int		check;
	char	**flags;

	n = 0;
	check = 0;
	if (!(*blist)->args)
		return (-1);
	if ((*blist)->args[i + 1] == '-' || ft_strlen((*blist)->args) < 2)
	{
		printf("%s", (*blist)->args);
		return (-1);
	}
	flags = ft_split((*blist)->args, ' ');
	check = ft_print_flag(flags, i, blist, check);
	while (flags[i])
		free(flags[i++]);
	free (flags);
	flags = NULL;
	if (check < i)
		return (1);
	return (0);
}

int	nextspace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i++])
	{
		if (str[i] == ' ')
			return (i);
	}
	return (i);
}

void	print_after(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}
