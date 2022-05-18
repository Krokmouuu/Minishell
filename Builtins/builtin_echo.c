/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:50:42 by ple-berr          #+#    #+#             */
/*   Updated: 2022/05/09 12:05:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

t_global		g_struct;

void	old_print_echo_arg(t_token **blist, t_env **t_env_list)
{
	int		i;
	int		n;
	t_env	*env;

	env = (*t_env_list);
	n = 1;
	i = 0;
	if ((*blist)->args[i] == '$' && (*blist)->quoted != 1)
	{
		if ((*blist)->args[i + 1] == '\0')
			printf("$");
		if ((*blist)->args[i + 1] == '?')
			printf("%d", (g_struct.exit_status));
		while ((ft_strcmp(env->str, &(*blist)->args[n]) != 0) && env->next)
			env = env->next;
		if (ft_strcmp(env->str, &(*blist)->args[n]) == 0)
			printf("%s", (env->value));
	}
	else
		printf("%s", ((*blist)->args));
}

void	quoted_echo_args(t_token **blist, t_env **t_env_list)
{
	int		i;
	int		n;
	char	**tab;
	t_env	*env;

	env = (*t_env_list);
	i = 0;
	n = 0;
	while ((*blist)->args[n] != '$' && (*blist)->args[n])
		write(1, &(*blist)->args[n++], 1);
	tab = ft_split(&(*blist)->args[n], '$');
	while (tab[i])
	{
		n = nextspace(tab[i]);
		while ((ft_strncmp(env->str, tab[i], n) != 0) && env->next != NULL)
			env = env->next;
		if (ft_strncmp(env->str, tab[i], n) == 0)
			ft_putstr(env->value);
		if (tab[i][0] == '?')
			ft_putnbr(g_struct.exit_status);
		print_after(tab[i]);
		env = (*t_env_list);
		i++;
	}
	free_tab(tab);
}

void	print_echo_args(t_token **blist, t_env **t_env_list)
{
	if ((*blist)->quoted != 1 && (*blist)->quoted == 2)
		quoted_echo_args(blist, t_env_list);
	else
		old_print_echo_arg(blist, t_env_list);
}

void	echo_avatar_two(t_token *read, t_env **t_env_list)
{
	while (read->next != NULL)
	{
		if ((read->type == 2 || read->type == 3) && read->next != NULL)
			read = read->next;
		if (read->args != NULL)
			print_echo_args(&read, t_env_list);
		if (read->next != NULL)
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
	g_struct.exit_status = 0;
	return (0);
}
