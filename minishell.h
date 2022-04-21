/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/04/21 20:01:56 by bleroy           ###   ########.fr       */
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

typedef struct s_token		t_token;
typedef struct s_env		t_env;

//* **************** Struct parse ****************

struct s_token
{
	char			*cmd;
	char			*flags;
	char			*args;
	char			*pipeorcrocodile;
	int				type;
	t_token			*next;
};

struct s_env
{
	char			**env_tab;
};

//* **************** Utils ****************
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *buf);

//* **************** Lexing ****************
char	*remove_spaces(char *str);
void	splitpipe(t_token **blist, char *str);
void	lexing(t_token **blist, char *str, char **env);
void	ft_split_all(t_token **blist, char *str);
char	*ft_get_cmd(char *str);
char	*ft_get_flags(char *str);
int		helperspace(char *str, int help);
int		quotespy(char *str, int help);
int		findquotes(char *str);
char	typequotes(char *str);
char	*skip2(char *str);
char	*takingnoquote(char *str, char quote);
int		lenwithoutquote(char *str);

//* **************** Lists ****************
t_token	*ft_create_list(void);
void	*ft_lstadd_back(t_token *pile);
void	init_list(t_token **list);
int		ft_list_length(t_token **pile);
void	free_list(t_token **list);
void	list_free_data(void *data);
void	*list_shift(t_token **blist);
void	list_clear(t_token **blist, void (*free_data)(void *data));
t_env	*ft_create_listenv(void);
void	init_env(t_env blist);

//* **************** Prompt & Cie ****************
void	exitshell(t_token **blist);
char	*input(void);
void	errorcmd(char *str);

//******************* Builtins commands *********
void	builtins(t_token **blist, char **env);
int		is_letter(char c);
void	pwd_command(char **env);
void	echo_command(t_token **blist);
char	*ft_find(char **env, char *str);
int		ft_findspace(char *str);
void	env_command(char **env);
void	export_command(t_token **blist, t_env **list_env);

#endif
