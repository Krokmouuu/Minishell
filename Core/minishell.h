/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:21 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/05 19:26:33 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define DQUOTE 34
# define SQUOTE 39

typedef struct s_token		t_token;
typedef struct s_env		t_env;

//* **************** Struct enum tokenizer ****************
typedef enum types
{
	FILE_OUT,
	FILE_IN,
	HERE_DOC,
	APPEND,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPES,
	DOLLARS,
	QUESTION_MARK,
	FLAGS,
}	t_types;
	// 0 //* >
	// 1 //* <
	// 2 //* <<
	// 3 //* >>
	// 4 //* '
	// 5 //* "
	// 6 //* |
	// 7 //* $
	// 8 //* ?
	// 9 //* -xxxx

//* **************** Struct lexing ****************
struct s_token
{
	char			*args;
	int				type;
	int				quoted;
	t_token			*next;
};

//* **************** Struct env ****************
struct	s_env
{
	char	*str;
	char	*equal;
	char	*value;
	t_env	*next;
};

//* **************** Utils ****************
void	rl_replace_line(const char *text, int clear_undo);
void	signal_function(int sig);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *c);
char	*ft_strdup_len(const char *c, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char set);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *str, char *buf);
int		whitespace(char *str);

//* **************** Lexing ****************
char	*remove_spaces(char *str);
int		lexing(t_token **blist, char *str, t_env **env_list, char **env);
void	ft_split_all(t_token **blist, char *str);
int		ft_get_cmd(t_token *blist, char *str);
int		helperspace(char *str, int help);
int		lenword(char *str);
int		noquote(t_token *temp, char *str);
char	*takingnoquote(char *str, char quote);
char	*takingnoquotehelper(char *str, char quote, char otherquote);
int		lenwithoutquote(char *str);
int		validquote(char *line, int index);
int		double_quote(t_token *temp, char *str);
int		single_quote(t_token *temp, char *str);
int		validquotebrother(char *uwu, char *owo, int i);
void	tokenizer(t_token **blist, int *save_fd);

//***************** Lists ****************
t_token	*ft_create_list(void);
void	*ft_lstadd_back(t_token *pile);
void	init_list(t_token **list);
int		ft_list_length(t_token **pile);
void	free_list(t_token **list);
void	list_free_data(void *data);
void	*list_shift(t_token **blist);
void	list_clear(t_token **blist, void (*free_data)(void *data));
t_env	*ft_create_listenv(void);
void	init_env(t_env **env_list);

//* **************** Prompt & Cie ****************
void	exitshell(t_token **blist);
int		prompt_here_doc(t_token **blist, t_token *read);
char	*input(void);
void	errorcmd(char *str, int i);

//******************* Builtins commands *********
int		builtins(t_token **blist, t_env **env_list, int toto);
int		pwd_command(t_token **blist, t_env **env);
int		echo_command(t_token **blist, t_env **t_env_list);
void	env_command(t_env **env_list, char **env);
int		export_command(t_token **blist, t_env **t_env_list);
int		unset_command(t_token **blist, t_env **env_list);
int		cd_command(t_token **blist, t_env **env_list);
int		exit_command(t_token **blist);

//******************* Builtins utils *********
char	*ft_find(char **env, char *str);
int		is_letter(char c);
int		ft_findspace(char *str);
int		ft_return_echo(int mama, int max, int check);
int		max(char **flags);
void	print_line(int check, char **flags, int i, int n);
int		get_builtin(char *str, char *cmd);
char	*ft_strjoin_exec(char const *s1, char const *s2, int n);
void	echo_avatar_two(t_token *read, t_env **t_env_list);
void	print_echo_args(t_token **blist, t_env **t_env_list);
int		ft_check_nflag(t_token **blist, int i);
int		ft_print_flag(char **flags, int i, t_token **blist, int check);

//******************* Builtins list utils *********
void	free_env_list(t_env **list);
void	fill_env_list(char **env, t_env **t_env_list);
int		print_list_env(t_env **read);
void	ft_lstadd_back_env(t_env **pile, char *line);
t_env	*create_env(void);
void	ft_lstadd_back_export(t_env **pile, char *line);

//******************* Redirection *********
int		redirect_in(t_token *read);
int		redirect_out(t_token *read, int i);
int		checkredirection(t_token **blist);
t_token	*new_list(t_token **blist, t_token **newlist);
void	restorefd(int *save_fd);
void	elskiper(t_token **blist, int type);
void	savefd(int *save_fd);

//******************* Execution *********
int		exec_cmd(t_token **blist, t_env **env_list, char **env);
char	*get_envp_path(t_env **env_list);
char	*get_value(t_env **env_list, char *str);

//******************* Execution redirection *********
char	**ft_get_args2(t_token **list, t_env **env_list);
int		ft_execve2(t_token **list, t_env **env_list, char **env, int *fd);
void	process_one2(t_token **list, t_env **env_list, char **env, int *fd);
int		exec_cmd2(t_token **blist, t_env **env_list, char **env, int *fd);
int		errorcmd2(char *str, int i, int *fd);
int		echo_command_redirect(t_token **blist, t_env **t_env_list);

#endif