/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:56:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/06 13:53:07 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	so_wrong(int error, t_pipex *pipex, int flag)
{
	if (flag != 1)
	{
		close(STDIN_FILENO);
		close(STDIN_FILENO);
		close(pipex->in_fd);
		close(pipex->out_fd);
		free_all(pipex);
	}
	exit(error);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->all_path != NULL)
	{
		while (pipex->all_path[++i])
		{
			free(pipex->all_path[i]);
			pipex->all_path[i] = NULL;
		}
		free(pipex->all_path);
		pipex->all_path = NULL;
	}
	i = -1;
	if (pipex->cmd != NULL)
	{
		while (pipex->cmd[++i])
		{
			free(pipex->cmd[i]);
			pipex->cmd[i] = NULL;
		}
		free(pipex->cmd);
		pipex->cmd = NULL;
	}
}

int	error_message(char *s1, int error)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(s1, 2);
	return (error);
}
