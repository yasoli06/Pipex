/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:03:20 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/01 18:30:46 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **final_cmd(char *cmd, t_pipe *pipex) - chequear esta fucion
{
	int	i;
	char **cmd_final;
	char *temp;

	if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) -1;
		while(cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_split(cmd));
	}
	cmd_final = ft_split(cmd, ' ');
	if (!cmd_final)
		error_message("Error spliting cmd\n", 0, pipex);
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
	
}

void init_pipex(char **av, t_pipe *pipex)
{
	pipex->in_fd = -1;
    pipex->out_fd = -1;
	pipex->all_path = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
    pipex->cmd1 = NULL;
    pipex->cmd2 = NULL;
	 
}

int	parsing(char **av, char *envp[], t_pipe *pipex, int i) 
{
	pipex->cmd1 = final_cmd(av[2], pipex);
	pipex->cmd2 = final_cmd(av[3], pipex);
	while (envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->all_path = ft_split(envp[i],':');
			pipex->all_path[0] = ft_substr(pipex->all_path[0], 5, ft_strlen(pipex->all_path[0]));
			break ;
		}
		i++;
	}
	if (!pipex->all_path)
		pipex->all_path = ft_split(DEF_PATH, ':');
	
	 / ver que hace esta /
	pipex->path1 = check_cmd_access(pipex, pipex->cmd1);
	pipex->path2 = check_cmd_access(pipex, pipex->cmd2);
	return (0);
}

int	main(int ac, char *av, char *envp[])
{
	t_pipe *pipex;
	pid_t	pid;
	int	fd[2];
	
	if (ac != 5)
		return(error_message("Invalid arguments\n", 0, pipex));
	if (!envp)
		return(error_message("Unexpected error\n", 0, pipex));
	pipex = malloc(sizof(t_pipe));
	if (!pipex)
		return(0);
	init_pipex (av,pipex); 
	parsing(av, envp, pipex, i);
	if (pipe(fd) < 0)
		error_message("Error en pipe\n", 0, pipex);
	pid = fork();
	if (pid < 0)
		error_message("Error en pid\n", 0, pipex);
	if (pid == 0)
		creat_child(envp, av[1], pipex, fd)
	else	
		creat_parent(envp, av[4], pipex, fd);
	waitpid(pid, NULL, 0);
	return (0);
}
