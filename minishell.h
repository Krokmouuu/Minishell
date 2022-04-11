/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/11 20:33:32 by bleroy           ###   ########.fr       */
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
typedef struct s_token
{
	char	*input;
	char	*cmd;
	char	*flag;
	char	*files;
	char	*sep;
	char	*cmd2;
	char	*flag2;
	char	*sep2;
}	t_token;

typedef struct s_parse
{
	char	*input;
	char	*env;
	char	**cmdsplit;
	t_token	*token;
}	t_parse;

//* **************** Utils ****************
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*whitespace(char *str);
void	*ft_calloc(size_t count, size_t size);

//* **************** Lexing ****************
char	*ft_get_cmd(char *str);
char	*ft_get_flags(char *str, t_parse *parse);
char	*ft_get_files(char *str);
void	fuckwhitespace(t_parse *parse);

void	lexing(t_parse *parse);
void	splitinput(char *str, t_parse *parse);

#endif