/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:56:52 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/01 18:20:11 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_up(t_pipe *pipex);

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