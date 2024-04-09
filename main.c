/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:45:02 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/09 18:46:57 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access_cmd(t_pipex *pipex, char **cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = px_barjoin(pipex->all_path[i], "/");
		final_path = px_strjoin(final_path, cmd[0]);
		if (!final_path)
			error_message("error to join\n", pipex, 0);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				error_message("access fail\n", pipex, 1);
			else
				return (final_path);
		}
		else
			free(final_path);
		i++;
	}
	error_message("Error Access\n", pipex, 1);
	return (0);
}

char	**final_cmd(char *cmd, t_pipex *pipex)
{
	int		i;
	char	**final_cmd;

	i = 0;
	if (strchr_count(cmd, '\'') > 0)
	{
		final_cmd = ft_split_quote(cmd, pipex);
		return (final_cmd);
	}
	else if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) - 1;
		while (cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_strlen(cmd));
	}
	final_cmd = ft_split(cmd, ' ');
	return (final_cmd);
}

void	parsing(char **av, char *envp[], t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->cmd1 = final_cmd(av[2], pipex);
	pipex->cmd2 = final_cmd(av[3], pipex);
	pipex->path1 = check_access_cmd(pipex, pipex->cmd1);
	pipex->path2 = check_access_cmd(pipex, pipex->cmd2);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->all_path = ft_split_pipex(pipex, envp[i] + 5, ':');
			break ;
		}
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split_pipex(pipex, DEF_PATH, ':');
}

void	init_pipex(t_pipex *pipex)
{
	pipex->j = -1;
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		fd[2];
	pid_t	pid;

	pipex = NULL;
	if (argc != 5)
		return (error_message("Invalid arguments\n", pipex, 0));
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error_message("Error malloc\n", pipex, 0);
	if (!envp)
		error_message("Unexpected error\n", pipex, 0);
	init_pipex(pipex);
	parsing(argv, envp, pipex);
	if (pipe(fd) < 0)
		error_message("Error en pipe\n", pipex, 0);
	pid = fork();
	if (pid < 0)
		error_message("Error en pid\n", pipex, 0);
	if (pid == 0)
		child_process(pipex);
}
