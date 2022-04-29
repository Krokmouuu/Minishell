/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:50:28 by ple-berr          #+#    #+#             */
/*   Updated: 2022/04/29 18:55:01 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

int	print_list_env(t_env **read)
{
	t_env	*list;

	list = (*read);
	while (list)
	{
		if (list->str != NULL)
			printf("%s", list->str);
		if (list->equal != NULL)
			printf("%s", list->equal);
		if (list->value != NULL)
			printf("%s", list->value);
		printf("\n");
		list = list->next;
	}
	return (0);
}

void	free_env_list(t_env **list)
{
	t_env	*lst;

	lst = (*list);
	while (lst)
	{
		lst = (*list)->next;
		free((*list)->str);
		free((*list)->value);
		free((*list));
		*list = lst;
	}
	free((*list));
	*list = NULL;
}

void	ft_lstadd_back_env(t_env **pile, char *line)
{
	t_env	*element;
	t_env	*tmp;
	int		i;

	i = 0;
	while (line[i] && line [i] != '=')
		i++;
	element = malloc(sizeof(t_env));
	element->str = ft_substr(line, 0, i);
	element->equal = ft_strdup("=");
	element->value = ft_strdup(&line[i + 1]);
	element->next = NULL;
	tmp = (*pile);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return ;
}

t_env	*create_env(void)
{
	t_env	*head;

	head = (malloc(sizeof(t_env)));
	if (head == NULL)
		return (NULL);
	head->str = NULL;
	head->equal = NULL;
	head->value = NULL;
	head->next = NULL;
	return (head);
}
