/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/06 17:22:42 by yaolivei         ###   ########.fr       */
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

typedef struct s_pipex	t_pipex;
struct	s_pipex
{
	int		in_fd;
	int		out_fd;
	int		ac;
	char	*av;
	int		fd;
	char	**all_path;
	char	**path1;
	char	**path2;
	char	**envp;
	char	*cmd1;
	char	*cmd2;
	pid_t	pid;
};

// MAIN // 
void	init_all_paths(t_pipex *pipex, char *envp[]);
int		get_data(char *argv[], char *envp[], t_pipex *pipex);
void	init_pipex(t_pipex *pipex);
int		main(int argc, char *argv[], char *envp[]);

// PROCESSES //
void	parent_process(t_pipex *pipex);
void	child_process(t_pipex *pipex);

// UTILS //
int		substr_awk(char const *s, char c);
char	**split_awk(char const *s, char c);
char	**get_cmd(t_pipex *pipex);
void	check_cmd_access(t_pipex *pipex);

// ERROR //
void	so_wrong(int error, t_pipex *pipex, int flag);
void	free_all(t_pipex *pipex);
int		error_message(char *s1, int error);

#endif