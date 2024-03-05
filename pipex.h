/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/05 19:53:58 by yaolivei         ###   ########.fr       */
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

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:
					/usr/local/go/bin:"
# define ACCESS_OK 0
# define ACCESS_KO 1

typedef struct s_pipex	t_pipex;
struct	s_pipex
{
	int		in_fd;
	int		out_fd;
	int		ac;
	int		*fd;
	char	**av;
	char	**all_path;
	char	**path_temp;
	char	**envp;
	char	**cmd;
	pid_t	pid;
	pid_t	pid_2;
	int		nb_cmd_curr;
};

// MAIN // 
void	init_pipex(t_pipex *pipex);
void	get_data(int argc, char *argv[], char *envp[], t_pipex *pipex);
int		main(int ac, char *av[], char *envp[]);

// PROCESSES //
void	get_cmd(t_pipex *pipex);
void	check_cmd_access(t_pipex *pipex);
void	open_file(char **av, t_pipex *pipex);
void	get_path(t_pipex *pipex);
void	child_process(t_pipex *pipex);

// ERROR //
void	so_wrong(int error, t_pipex *pipex, int flag);
void	free_all(t_pipex *pipex);
int		error_message(char *s1, int error);

#endif