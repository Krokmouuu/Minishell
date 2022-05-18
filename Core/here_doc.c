/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:42:23 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/17 18:26:54 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_temporary_file(void)
{
	int	fd;

	fd = open(".inv", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	return (fd);
}

static	void	get_and_write_input(int tmp_fd, t_token *read)
{
	char	*str;

	signal(SIGINT, heredoc_stopper);
	while (1)
	{
		str = readline("Ici Doc > ");
		if (!str)
		{
			close(tmp_fd);
			exit(0);
		}
		if (get_builtin(read->args + 2, str))
			ft_putendl_fd(str, tmp_fd);
		else
		{
			close(tmp_fd);
			free(str);
			break ;
		}
		free(str);
	}
	exit(0);
}

static void	clear_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(".inv", O_WRONLY | O_TRUNC, 0600);
	close(tmp_fd);
}

void	make_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(".inv", O_RDONLY);
	unlink(".inv");
	dup2(tmp_fd, 0);
	close(tmp_fd);
}

int	prompt_here_doc(t_token *read, int *save_fd)
{
	int			tmp_fd;
	int			save_fd_out;
	pid_t		pid;
	int			status;

	if (ft_strlen(read->args) == 2)
		return (50);
	tmp_fd = create_temporary_file();
	if (tmp_fd == -1)
		return (50);
	save_fd_out = dup(1);
	dup2(save_fd[1], STDOUT_FILENO);
	pid = fork();
	g_struct.h = 1;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pid == 0)
		get_and_write_input(tmp_fd, read);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		clear_tmp_file_input();
	make_tmp_file_input();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
	return (1);
}
