/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:24:43 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/09 18:46:47 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	clean_pipex(t_pipex *pipex)
{
	if (pipex && pipex->all_path)
		free_all(pipex->all_path);
	if (pipex && pipex->path1)
		free(pipex->path1);
	if (pipex && pipex->path2)
		free(pipex->path2);
	if (pipex && pipex->cmd1)
		free_all(pipex->cmd1);
	if (pipex && pipex->cmd2)
		free_all(pipex->cmd2);
	if (pipex)
		free(pipex);
	pipex = NULL;
}

int	error_message(char *msg, t_pipex *pipex, int flag)
{
	if (pipex)
		clean_pipex(pipex);
	if (flag == 1)
		perror(msg);
	else
		write(2, msg, ft_strlen(msg));
	exit(errno);
}

char	**free_matrix(char **matrix, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(matrix[i]);
		i++;
	}
	return (NULL);
}
