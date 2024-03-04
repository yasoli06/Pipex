/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/04 17:07:26 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// perror
# include <stdio.h>
# include <errno.h>
// strerror
# include <string.h>
// exit
# include <stdlib.h>
//open close read write access dup dup2 execve fork pipe
# include <unistd.h>
// open access
# include <fcntl.h>
// fork wait
# include <sys/types.h>
//wait
# include <sys/wait.h>
//libft
# include "libft/libft.h"

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:"
# define ACCESS_OK 0
# define ACCESS_KO 1

typedef struct s_pipe
{
    int in_fd;
    int out_fd;
    char *all_path;
    char *path1;
    char *path2;
    char **cmd1;
    char **cmd2;
    pid_t   pid;
    pid_t   pid_2;
    int     nb_cmd_curr;

}   t_pipe;

// MAIN // 
char	**final_cmd(char *cmd, t_pipe *pipex);
char	**check_cmd_access(char *cmd, t_pipe *pipex);
void    init_pipex(t_pipe *pipex);
int parsing(char **av, char *envp[], t_pipe *pipex);
int main(int ac, char **av, char *envp[]);

// PROCESSES //
void    open_file (t_pipe *pipex);
void    child_process(t_pipe *pipex);

// ERROR //
void    free_all(char **freedom);
void	clean_up(t_pipe *pipex);
void	error_message(char *message, int flag, t_pipe *pipe);

#endif