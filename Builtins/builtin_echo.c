/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:50:42 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:54:49 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

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
	if (flags[i - 1][n - 1] != 'n' && (*blist)->args != NULL)
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

void	print_echo_args(t_token **blist, t_env **t_env_list)
{
	int		i;
	int		n;
	t_env	*env;

	env = (*t_env_list);
	n = 1;
	i = 0;
	if ((*blist)->args[i] == '$' && (*blist)->quoted != 1)
	{
		while ((ft_strcmp(env->str, &(*blist)->args[n]) != 0) && env->next)
			env = env->next;
		if (ft_strcmp(env->str, &(*blist)->args[n]) == 0)
			printf("%s", env->value);
	}
	else
		printf("%s", (*blist)->args);
}

void	echo_avatar_two(t_token *read, t_env **t_env_list)
{
	while (read->next != NULL)
	{
		if (read->args != NULL)
			print_echo_args(&read, t_env_list);
		read = read->next;
		if (read->next != NULL)
			printf(" ");
	}
}

int	echo_command(t_token **blist, t_env **t_env_list)
{
	int		ndash;
	int		i;
	t_token	*read;

	read = (*blist);
	i = 0;
	ndash = 0;
	read = read->next;
	while (read->type == 9 && read->next != NULL)
	{
		if (ft_check_nflag(&read, i) > 0)
			ndash = 1;
		else
		{
			read = read->next;
			break ;
		}
		read = read->next;
	}
	echo_avatar_two(read, t_env_list);
	if (ndash == 0)
		printf("\n");
	return (0);
}
