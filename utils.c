/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:12:05 by yaolivei          #+#    #+#             */
/*   Updated: 2024/03/06 16:12:15 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	substr_awk(char const *s, char c)
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

char	**split_awk(char const *s, char c)
{
	int		start;
	int		i;
	int		j;
	char	**ret;

	ret = malloc(sizeof(char *) * (substr_awk(s, c) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	while (s[i++] != '\'')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && s[i + 1] == c || s [i + 1] == '\'')
		{
			ret[j++] = ft_substr(s, start, i - start + 1);
			if (ret[j - 1] == NULL)
				return (0);
		}
	}
	ret[j] = NULL;
	return (ret);
}

char	**get_cmd(t_pipex *pipex)
{
	int		i;
	char	**temp;

	if (ft_strncmp(pipex->cdm, "awk", 3) == 0)
	{
		temp = split_awk(pipex->cmd, ' ');
		i = 0;
		while (pipex->cmd[i] != '\'')
			i++;
		temp[i] = ft_substr(pipex->cmd, i, ft_strlen(pipex->cmd));
		temp[i + 1] = NULL;
		return (temp);
	}
	else if (pipex->cmd[0] == '/')
	{
		i = ft_strlen(pipex->cmd) - 1;
		while (pipex->cmd[i] != '/')
			i--;
		pipex->cmd = ft_substr(pipex->cmd, i + 1, ft_strlen(pipex->cmd));
	}
	temp = ft_split(pipex->cmd, ' ');
	return (temp);
}

void	check_cmd_access(t_pipex *pipex)
{
	char	*final_path;
	int		i;

	i = 0;
	while (pipex->all_path[i])
	{
		final_path = ft_strjoin(pipex->all_path[i], '\'');
		final_path = ft_strjoin(final_path, pipex->cmd[0]);
		if (!final_path)
			error_message("Error paths\n", 11);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK != 0))
				error_message("Error Access\n", 11);
			else
				return (final_path);
		}
		i++;
	}
	error_message("Error 3\n", 11);
	return (0);
}
