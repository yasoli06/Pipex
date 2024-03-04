/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:56:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/04 16:48:38 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_all(char **freedom)
{
    int i = 0;

    while(freedom[i])
    {
        free(freedom[i])
        i++;
    }
    free(freedom);
    freedom = NULL;
}
void	clean_up(t_pipe *pipex)
{
    if(pipex && pipex->all_path)
        free_all(pipex->all_path);
    if(pipex && pipex->path1)
        free(pipex->path1);
    if(pipex && pipex->path2)
        free(pipex->path2);
    if(pipex && pipex->cmd1)
        free_all(pipex->cmd1);
    if(pipex && pipex->cmd2)
        free_all(pipex->cmd2);
    if(pipex)
        free(pipex);
    pipex = NULL; 
}

void	error_message(char *message, int flag, t_pipe *pipe)
{
    if (pipex)
        clean_up(pipex);
    write(2, "pipex: ", 7);
    if (flag == 0)
        perror(message);
    else
    {
        write(2, message, ft_strlen(message));
        exit(flag);
    }
    exit(errno);
}