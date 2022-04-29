/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:20:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/29 18:56:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Core/minishell.h"

void	*ft_lstadd_back(t_token *pile)
{
	t_token	*element;
	t_token	*tmp;

	element = malloc(sizeof(t_token));
	element->args = NULL;
	element->type = -1;
	element->quoted = -10;
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
	head->args = NULL;
	head->type = -1;
	head->quoted = -10;
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
		printf("Arg %d -> %s | Type -> %d\n", i, temp->args, temp->type);
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
		free((*list)->args);
		free((*list));
		*list = lst;
	}
	free((*list));
	*list = NULL;
}
