/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:03:20 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/05 20:02:22 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path_temp = NULL;
	pipex->cmd = NULL;
	pipex->ac = -1;
	pipex->av = NULL;
	pipex->envp = NULL;
	pipex->fd = NULL;
	pipex->nb_cmd_curr = 2;
}

void	get_data(int argc, char *argv[], char *envp[], t_pipex *pipex)
{
	init_pipex(pipex);
	pipex->ac = argc;
	pipex->av = argv;
	pipex->envp = envp;
	pipex->nb_cmd_curr = argc - 3;
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	*pipex;
	int		fd[2];

	pipex = NULL;
	if (ac != 5)
		error_message("Invalid arguments\n", 0);
	if (!envp)
		error_message("Unexpected error\n", 1);
	if (pipe(fd) < 0)
		error_message("Error en pipe\n", 2);
	get_data (ac, av, envp, pipex);
	open_file(av, pipex);
	get_path(pipex);
	child_process(pipex);
	close(fd[0]);
	close(fd[1]);
	waitpid(pipex->pid, NULL, 0);
	waitpid(pipex->pid_2, NULL, 0);
	free_all(pipex);
	close(pipex->in_fd);
	close(pipex->out_fd);
	return (0);
}
