/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:47:27 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/10 19:35:54 by yaolivei         ###   ########.fr       */
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

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:\
			/usr/sbin:/sbin:/usr/local/go/bin:"
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
void	init_all_paths(t_pipex *pipex, char *envp[]);
int		parsing(char **av, char *envp[], t_pipex *pipex);
void	init_pipex(t_pipex *pipex);

// PIPEX //
char	*check_access_cmd(t_pipex *pipex, char **cmd);
char	**final_cmd(char *cmd, t_pipex *pipex);
int		subsrt_space(const char *s, char c);
void	split_quotes(char **res, char *cmd, int i, int j);
char	**ft_split_quote(char *cmd, t_pipex *pipex);

// PROCESSES //
void	parent_process(char **envp, char *argv, t_pipex *pipex, int fd[]);
void	child_process(char **envp, char *argv, t_pipex *pipex, int fd[]);

// UTILS //
int		strchr_count(char *str, char c);
char	*px_barjoin(char *path, char *buf);
char	*px_strjoin(char *path, char *buf);
char	*px_strtrim(char *s1, char *set);

// ERROR //
void	free_all(char **arr);
void	clean_pipex(t_pipex *pipex);
int		error_message(char *msg, t_pipex *pipex, int flag);
char	**free_matrix(char **matrix, int num);

#endif