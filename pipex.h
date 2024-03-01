/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/01 18:20:15 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// perror
# include <stdio.h>
# include <string.h>
//open close read write access dup dup2 execve fork pipe
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
//libft
# include "libft/libft.h"

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:"

typedef struct s_pipe
{
    int in_fd;
    int out_fd;
    char *all_path;
    char *path1;
    char *path2;
    char **cmd1;
    char **cmd2;

}   t_pipe;

// MAIN // 
char	**final_cmd(char *cmd, t_pipe *pipex);
char	**check_cmd_access(char **cmd, t_pipe *pipex);
void	init_pipex(char **av, t_pipe *pipex);
int	parsing(char **av, char *envp[], t_pipe *pipex);
int	main(int ac, char *av, char *envp[]);

// ERROR //
void	clean_up(t_pipe *pipex);
void	error_message(char *message, int flag, t_pipe *pipe);

#endif