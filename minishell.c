/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:50:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/07 17:38:00 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{	
	t_parse	parse;
	
	parse.env = getenv("PATH");
	while (1)
	{
		parse.input = readline("Minishell$ ");
		lexing(&parse);
	}
	return (0);
}