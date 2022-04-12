/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:35:32 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/12 14:58:29 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexing(t_parse *parse)
{
	int	i;

	i = 0;
	fuckwhitespace(parse);
	splitinput(parse->token->input, parse);
	while (parse->token->input[i] != '\0')
	{
		if (parse->token->input[i] == '|')
		{
			if (parse->token->input[i + 1] == ' ')
				i++;
			while (parse->token->input[i] == ' ')
				i++;
			splitinput(&parse->token->input[i], parse);
		}
		i++;
	}
	checkcmd(parse);
	// printf("Cmd -> %s\n", parse->token->cmd);
	// printf("Flag -> %s\n", parse->token->flag);
	// printf("Files -> %s\n", parse->token->files);

}
