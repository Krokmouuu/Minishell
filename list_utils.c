/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:20:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 16:57:26 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_lstadd_back(t_token *pile)
{
	t_token	*element;
	t_token	*tmp;

	element = malloc(sizeof(t_token));
	element->cmd = NULL;
	element->flags = NULL;
	element->args = NULL;
	element->pipeorcrocodile = NULL;
	element->type = -1;
	element->next = NULL;
	tmp = pile;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (element);
}

t_token	*ft_create_list(void)
{
	t_token	*head;

	head = (malloc(sizeof(t_token)));
	if (head == NULL)
		return (NULL);
	head->cmd = NULL;
	head->flags = NULL;
	head->args = NULL;
	head->pipeorcrocodile = NULL;
	head->type = -1;
	head->next = NULL;
	return (head);
}

void	init_list(t_token **list)
{
	t_token	*new_node;

	new_node = ft_create_list();
	new_node->next = (*list);
	*list = new_node;
}

int	ft_list_length(t_token **list)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = (*list);
	while (temp != NULL)
	{
		printf("Cmd -> %s\n", temp->cmd);
		printf("Flag -> %s\n", temp->flags);
		printf("Args -> %s\n", temp->args);
		i++;
		temp = temp->next;
	}
	return (i);
}

void	free_list(t_token **list)
{
	t_token	*lst;

	lst = (*list);
	while (lst)
	{
		lst = (*list)->next;
		free((*list)->cmd);
		free((*list)->flags);
		free((*list)->args);
		free((*list));
		*list = lst;
	}
	free((*list));
	*list = NULL;
}
