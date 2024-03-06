/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:35:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/06 17:18:33 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_pipex *pipex);
{
	close(pipex->fd[1]);
	pipex->out_fd = open (pipex->av, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (pipex->out_fd == -1)
		error_message(strerror(1), 12);
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		error_message("dup2 fd[0]\n", 12);
	}
	if (dup2(pipex->out_fd, STDOUT_FILENO) < 0)
	{
		close(pipex->out_fd);
		error_message("dup2 fd\n", 12);
	}
	close(pipex->out_fd);
	if (execve(pipex->path2, pipex->cmd2, envp) == -1)
	{
		error_message("Error en execve\n", 12);
	}
	close(fd[0]);
}

void	child_process(t_pipex *pipex)
{
	close(fd[0]);
	pipex->in_fd = open (pipex->av, O_RDONLY);
	if (pipex->in_fd == -1)
		error_message("No lee el infile\n", 13);
	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
	{
		close(pipex->in_fd);
		error_message("dup2 fd\n", 13);
	}
	close(pipex->in_fd);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_message("dup out a f[1] fd\n", 13);
	if (execve(pipex->path1, pipex->cmd1, envp) == -1)
		error_message("Error en execve\n", 13);
}
