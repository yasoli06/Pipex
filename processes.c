/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:53:42 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/10 19:56:22 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **envp, char *argv, t_pipex *pipex, int fd[])
{
	close(fd[1]);
	pipex->out_fd = open(argv, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->out_fd == -1)
		error_message("outfile error\n", pipex, 1);
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		error_message("dup2 error\n", pipex, 1);
	}
	if (dup2(pipex->out_fd, STDOUT_FILENO) < 0)
	{
		close(pipex->out_fd);
		error_message("dup2 error\n", pipex, 0);
	}
	close(pipex->out_fd);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
		error_message("execve error\n", pipex, 1);
	close(fd[0]);
}

void	child_process(char **envp, char *argv, t_pipex *pipex, int fd[])
{
	close(fd[0]);
	pipex->in_fd = open(argv, O_RDONLY);
	if (pipex->in_fd == -1)
		error_message("infile error\n", pipex, 1);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		error_message("Error dup2\n", pipex, 1);
	}
	close(pipex->in_fd);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_message("outfile error\n", pipex, 1);
	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		error_message("execve error\n", pipex, 1);
}
