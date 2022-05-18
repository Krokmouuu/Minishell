/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:00:06 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:58:25 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	get_equal(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '=' && line[i])
		i++;
	return (i + 1);
}

t_env	*setup_export(int i, char *line)
{
	t_env	*element;

	element = malloc(sizeof(t_env));
	element->str = ft_substr(line, 0, i - 1);
	element->equal = ft_strdup("=");
	element->value = ft_strdup(&line[i]);
	element->next = NULL;
	return (element);
}

int	ft_lstadd_back_export_helper(t_env *element, t_env *tmp, int i)
{
	if (i == 0)
	{
		free(tmp->next->str);
		free(tmp->next->equal);
		free(tmp->next->value);
		free(tmp->next);
		tmp->next = element;
	}
	else if (i == 1)
	{
		element->next = tmp->next->next;
		free(tmp->next->str);
		free(tmp->next->equal);
		free(tmp->next->value);
		free(tmp->next);
		tmp->next = element;
	}
	return (0);
}

int	ft_lstadd_back_export(t_env **pile, char *line, int check)
{
	int		i;
	int		n;
	t_env	*element;
	t_env	*tmp;

	n = 0;
	i = get_equal(line);
	element = setup_export(i, line);
	tmp = (*pile);
	if (check == 0)
		return (0);
	while (tmp->next != NULL)
	{
		if (get_builtin(tmp->next->str, element->str) == 0)
		{
			if (tmp->next->next == NULL)
				return (ft_lstadd_back_export_helper(element, tmp, 0));
			else if (tmp->next->next != NULL)
				return (ft_lstadd_back_export_helper(element, tmp, 1));
			return (0);
		}
		tmp = tmp->next;
	}
	tmp->next = element;
	return (0);
}

int	export_command(t_token **blist, t_env **t_env_list)
{
	int		i;
	int		check;
	t_env	*list;
	t_token	*read;

	i = -1;
	check = 0;
	list = (*t_env_list);
	read = (*blist)->next;
	print_list_env_v2(t_env_list, read);
	while (read->args != NULL)
	{
		while (read->args[++i])
		{
			if (read->args[i] == '=')
				check = 1;
			if (check == 0 && read->args[0] >= '0' && read->args[0] <= '9')
				break ;
		}
		check = ft_lstadd_back_export(t_env_list, read->args, check);
		read = read->next;
		i = -1;
	}
	g_struct.exit_status = 0;
	return (0);
}
