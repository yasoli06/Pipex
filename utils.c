/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:07 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/09 18:45:51 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static size_t	count_w(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == '\0' && s[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_pipex(t_pipex *pipex, char *s, char c)
{
	int		i;
	int		j;
	char	**matrix;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	matrix = malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!matrix)
		error_message("error en matrix\n", pipex, 0);
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1 == c])
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1 == '\0']))
		{
			matrix[j] = ft_substr(s, start, (i - start + 1));
			if (matrix[j - 1] == NULL)
				free_matrix(matrix, j - 1);
		}
		i++;
	}
	matrix[j] = NULL;
	return (matrix);
}
