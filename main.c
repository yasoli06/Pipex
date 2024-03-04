/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:03:20 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/04 17:22:52 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **final_cmd(char *cmd, t_pipe *pipex)
{
	int	i;
	char **cmd_final;
	char *temp;

	if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) -1;
		while(cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_strlen(cmd));
	}
	cmd_final = ft_split(cmd, ' ');
	if (!cmd_final)
		error_message("Error spliting cmd\n", 3, pipex);
	temp = NULL;
	i = -1;
	while(cmd_final[i++])
	{
		temp = cmd_final[i];
		cmd_final[i] = ft_strtrim(cmd_final[i], "'");
		free(temp);
	}
	return(cmd_final);
}

char **check_cmd_access(char *cmd, t_pipe *pipex)
{
	char	*final_path;
	int	i;
	char **result;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = ft_strjoin(pipex->all_path, "/");
		final_path = ft_strjoin(final_path, cmd);
		if (!final_path)
		error_message("Error all paths\n", 4, pipex);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				error_message("Acess fail\n", 5, pipex);
			else
			{
				result = (char **) malloc(sizeof(char *) *2);
				if (!result)
					error_message("Memory allocation error\n", 5, pipex);
				result[0] = final_path;
				result[1] = NULL;
				return(result);
			}
		i++;
		}
	}
	error_message("Error 3\n", 6, pipex);
	return (0);
}

void init_pipex(t_pipe *pipex)
{
	pipex->in_fd = -1;
    pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
    pipex->cmd1 = NULL;
    pipex->cmd2 = NULL;
	 
}

int	parsing(char **av, char *envp[], t_pipe *pipex) 
{
	int i = 0;
	pipex->cmd1 = final_cmd(av[2], pipex);
	pipex->cmd2 = final_cmd(av[3], pipex);
	while (envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->all_path = ft_split(envp[i],':');
			pipex->all_path[0] = ft_substr(pipex->all_path, 5, ft_strlen(pipex->all_path[0]));
			break ;
		}
		i++;
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split(DEF_PATH, ':');
	pipex->path1 = check_cmd_access(pipex, pipex->cmd1);
	pipex->path2 = check_cmd_access(pipex, pipex->cmd2);
	return (0);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipe *pipex;
	pid_t	pid;
	int	fd[2];
	
	if (ac != 5)
		error_message("Invalid arguments\n", 0, pipex);
	if (!envp)
		error_message("Unexpected error\n", 1, pipex);
	pipex = malloc(sizeof(t_pipe));
	if (!pipex)
		return(0);
	init_pipex (av,pipex); 
	parsing(av, envp, pipex);
	if (pipe(fd) < 0)
		error_message("Error en pipe\n", 2, pipex);
	open_file(pipex);
	child_process(pipex);
	close(fd[0]);
	close(fd[1]);
	waitpid(pipex->pid, NULL, 0);
	waitpid(pipex->pid_2, NULL, 0);
	free_all(&pipex);
	close(pipex->in_fd);
	close(pipex->out_fd);
	return (EXIT_SUCESS);
}
