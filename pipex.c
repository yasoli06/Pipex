/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:40:55 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/10 19:25:40 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access_cmd(t_pipex *pipex, char **cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = px_barjoin(pipex->all_path[i], "/");
		final_path = px_strjoin(final_path, cmd[0]);
		if (!final_path)
			error_message("error to join\n", pipex, 0);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
				error_message("access fail\n", pipex, 1);
			else
				return (final_path);
		}
		else
			free(final_path);
		i++;
	}
	error_message("Error Access\n", pipex, 1);
	return (0);
}

char	**final_cmd(char *cmd, t_pipex *pipex)
{
	int		i;
	char	**final_cmd;

	i = 0;
	if (strchr_count(cmd, '\'') > 0)
	{
		final_cmd = ft_split_quote(cmd, pipex);
		return (final_cmd);
	}
	else if (cmd[0] == '/')
	{
		i = ft_strlen(cmd) - 1;
		while (cmd[i] != '/')
			i--;
		cmd = ft_substr(cmd, i + 1, ft_strlen(cmd));
	}
	final_cmd = ft_split(cmd, ' ');
	return (final_cmd);
}

int	subsrt_space(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\'')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 34))
			count++;
		i++;
	}
	return (count);
}

void	split_quotes(char **res, char *cmd, int i, int j)
{
	int	flag;
	int	start;

	flag = 0;
	while (cmd[i])
	{
		if (cmd[i] != '\'' && cmd [i - 1] == '\'' && flag == 0)
		{
			start = i;
			flag = 1;
			while (cmd[i] != '\'')
				i++;
			res[j++] = ft_substr(cmd, start, i - start);
		}
		else if (cmd[i] == '\'' && flag == 1)
			flag = 0;
		i++;
	}
}

char	**ft_split_quote(char *cmd, t_pipex *pipex)
{
	int		i;
	int		start;
	char	**res;

	start = 0;
	i = 0;
	res = malloc(sizeof(char *) * (subsrt_space(cmd, ' ')
				+ (strchr_count(cmd, '\'' / 2)) + 1));
	if (!res)
		return (NULL);
	while (cmd[i++] != '\'' && cmd[i] != '\0')
	{
		if (i > 0 && cmd[i] != ' ' && cmd[i - 1] == ' ')
			start = i;
		if (cmd[i] != ' ' && (cmd[i + 1] == ' '))
		{
			res[pipex->j] = ft_substr(cmd, start, i - start + 1);
			if (!res[pipex->j])
				return (NULL);
			pipex->j++;
		}
	}
	split_quotes(res, cmd, i, pipex->j);
	return (res);
}
