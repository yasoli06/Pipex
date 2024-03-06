/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:03:20 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/06 17:22:56 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_all_paths(t_pipex *pipex, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->all_path = ft_split(envp[i], ':');
			pipex->all_path[0] = ft_substr(pipex->all_path[0], 5,
					ft_strlen(pipex->all_path[0]));
			break ;
		}
		i++;
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split(DEF_PATH, ':');
}

int	get_data(char *argv[], char *envp[], t_pipex *pipex)
{
	init_all_paths(pipex, envp);
	pipex->cdm1 = get_cmd(av[2]);
	pipex->cdm2 = get_cmd(av[3]);
	pipex->path = check_cmd_access(pipex, pipex->cdm1);
	pipex->path2 = check_cmd_access(pipex, pipex->cdm2);
	return (0);
}

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	int		fd[2];

	pipex = NULL;
	if (argc != 5)
		error_message("Invalid arguments\n", 0);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error_message("Error Malloc\n", 0);
	if (!envp)
		error_message("Unexpected error\n", 0);
	init_pipex(pipex);
	get_data (argv, envp, pipex);
	if (pipe(fd) < 0)
		error_message("Error en pipe\n", 0);
	pipex->pid = fork();
	if (pipex->pid < 0)
		error_message("Error en pid\n", 0);
	if (pipex->pid == 0)
		child_process(pipex);
	waitpid(pipex->pid, NULL, 0);
	if (pipex->pid != 0)
		parent_process(pipex);
	return (0);
}
