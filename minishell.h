/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/11 16:02:46 by bleroy           ###   ########.fr       */
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
# include <string.h>

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
	char	**env;
	char	**cmdsplit;
	t_token	*token;
}	t_parse;

//* **************** Utils ****************
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*whitespace(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *c);
char	*ft_strjoin(char const *s1, char const *s2, int n);

void	lexing(t_parse *parse);
void	fuckwhitespace(t_parse *parse);
void	splitinput(t_parse *parse);
int 	checkcmd(t_parse *parse);
char	*ft_find(char **env, char *str);


#endif