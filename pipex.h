/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/09 18:40:59 by yaolivei         ###   ########.fr       */
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
	int		j;
	char	**all_path;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
};

// MAIN // 
char	*check_access_cmd(t_pipex *pipex, char **cmd);
char	**final_cmd(char *cmd, t_pipex *pipex);
void	parsing(char **av, char *envp[], t_pipex *pipex);
void	init_pipex(t_pipex *pipex);

// PROCESSES //
// void	parent_process(t_pipex *pipex);
void	child_process(t_pipex *pipex);

// UTILS //
int		subsrt_space(const char *s, char c);
void	split_quotes(char **res, char *cmd, int i, int j);
char	**ft_split_quote(char *cmd, t_pipex *pipex);
//static size_t count_w (char *s, char c);
char	**ft_split_pipex(t_pipex *pipex, char *s, char c);

// UTILS2 //
int		strchr_count(char *str, char c);
char	*px_barjoin(char *path, char *buf);
char	*px_strjoin(char *path, char *buf);

// ERROR //
// void	so_wrong(int error, t_pipex *pipex, int flag);
// void	free_all(t_pipex *pipex);
// int		error_message(char *s1, int error);
char	**free_matrix(char **matrix, int num);
int		error_message(char *msg, t_pipex *pipex, int flag);

#endif