/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:45:02 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/10 19:18:55 by yaolivei         ###   ########.fr       */
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
			pipex->all_path[0] = px_strtrim(pipex->all_path[0], "PATH=");
			return ;
		}
		i++;
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split (DEF_PATH, ':');
}

int	parsing(char **av, char *envp[], t_pipex *pipex)
{
	init_all_paths(pipex, envp);
	pipex->cmd1 = final_cmd(av[2], pipex);
	pipex->cmd2 = final_cmd(av[3], pipex);
	pipex->path1 = check_access_cmd(pipex, pipex->cmd1);
	pipex->path2 = check_access_cmd(pipex, pipex->cmd2);
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
	pipex->j = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		fd[2];
	pid_t	pid;

	pipex = NULL;
	if (argc != 5)
		error_message("Invalid arguments\n", pipex, 0);
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
		child_process(envp, argv[1], pipex, fd);
	waitpid(pid, NULL, 0);
	if (pid != 0)
		parent_process(envp, argv[4], pipex, fd);
	return (0);
}
