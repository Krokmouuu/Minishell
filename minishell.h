/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/07 18:22:20 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>

//* Struct Parse
typedef struct	s_parse
{
	char	*input;
	char	*env;
	char	**cmdsplit;
}	t_parse;

//* **************** Utils ****************
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	**args(char **str);
void	lexing(t_parse *parse);
char	**splitinput(t_parse *parse);
char	*ft_space(t_parse *parse);
#endif