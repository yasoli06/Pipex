/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:35:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/05 20:01:18 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(t_pipex *pipex)
{
	int		i;
	char	*temp;

	pipex->cmd = ft_split(pipex->av[pipex->nb_cmd_curr], ' ');
	if (!pipex->cmd)
		error_message("Error split cmd\n", 6);
	i = -1;
	temp = NULL;
	while (pipex->cmd[++i])
	{
		temp = pipex->cmd[i];
		pipex->cmd[i] = ft_strtrim(pipex->cmd[i], "'");
		free(temp);
	}
}

void	check_cmd_access(t_pipex *pipex)
{
	int		i;
	char	*cmd;

	get_cmd(pipex);
	i = 0;
	while (pipex->all_path[i])
	{
		cmd = ft_strjoin(pipex->all_path[i], (const char *)pipex->cmd[0]);
		if (access(cmd, F_OK) == 0
			&& execve(cmd, pipex->cmd, pipex->envp) == -1)
		{
			free(cmd);
			error_message("Error executing cmd\n", 7);
		}
		free(cmd);
		i++;
	}
	error_message("Error to find path\n", 8);
}

void	open_file(char **av, t_pipex *pipex)
{
	pipex->in_fd = open(av[1], O_RDONLY);
	pipex->out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->in_fd < 0)
	{
		if (pipex->out_fd >= 0)
			close(pipex->out_fd);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		error_message("Error while open file\n", 9);
	}
	if (pipex->out_fd < 0)
	{
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		error_message("Error while open file\n", 10);
	}
}

void	get_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (!ft_strnstr(pipex->envp[i], "PATH=", 5))
		i++;
	pipex->path_temp = ft_split(pipex->envp[i] + 5, ':');
	if (pipex->path_temp == NULL)
		error_message("Error spliting path\n", 11);
	i = 0;
	while (pipex->path_temp[i])
		i++;
	pipex->all_path = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (pipex->path_temp[++i])
		pipex->all_path[i] = ft_strjoin(pipex->path_temp[i], "/");
	pipex->all_path[i] = NULL;
	i = 0;
	while (pipex->path_temp[i])
	{
		free(pipex->path_temp[i]);
		i++;
	}
	free(pipex->path_temp);
}

void	child_process(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		error_message("Error creating fork\n", 12);
	if (pipex->pid == 0)
	{
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		dup2(pipex->in_fd, STDIN_FILENO);
		check_cmd_access(pipex);
	}
	pipex->pid_2 = fork ();
	if (pipex->pid_2 == -1)
		error_message("Error creating fork\n", 12);
	if (pipex->pid_2 == 0)
	{
		pipex->nb_cmd_curr++;
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		dup2(pipex->out_fd, STDOUT_FILENO);
		check_cmd_access(pipex);
	}
}
