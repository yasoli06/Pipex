/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:35:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/04 17:06:49 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

 void open_file (t_pipe *pipex)
 {
    pipex->in_fd = open(av, R_ONLY);
    pipex->out_fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (pipex->in_fd < 0)
    {
        if (pipex->out_fd >= 0)
            close (pipex->out_fd);
        close(pipex->fd[0]);
        close(pipex->fd[1]);
		error_message("Error while open file\n", 7, pipex);
    }
	if (pipex->out_fd < 0)
    {
        close(pipex->fd[0]);
        close(pipex->fd[1]);
		error_message("Error while open file\n", 8, pipex);
    }
}

void    child_process(t_pipe *pipex)
{
  pipex->pid = fork();
  if (pipex->pid == -1)
  	error_message("Error creating fork\n", 9, pipex);
  if (pipex->pid == 0)
  		//redirecionando a saída padrão para o pipe
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		//redirecionando a entrada padrão para o infile
		dup2(pipex->fd_inf, STDIN_FILENO);
		check_cmd_access(cmd[0], pipex);
	pipex->pid_2 = fork ();
	if (pipex->pid_2 == -1)
		error_message("Error creating fork\n", 9, pipex);
	if (pipex->pid_2 == 0)
	{
		pipex->nb_cmd_curr++;
		//redirecionando a entrada padrão para o pipe
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		//redirecionando a saída padrão para o outfile
		dup2(pipex->fd_outf, STDOUT_FILENO);
		check_cmd(pipex);
	}
}
