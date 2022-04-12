/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/11 18:51:29 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{	
	t_parse	parse;

	(void)argc;
	(void)argv;
	parse.token = malloc(sizeof(t_parse));
	parse.env = env;
	while (1)
	{
		parse.input = readline("Minishell$ > ");
		if (parse.input == NULL)
			break ;
		lexing(&parse);
		if (parse.input[0] != '\0')
			add_history(parse.input);
	}
	return (0);
}
