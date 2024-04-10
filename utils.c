/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:07 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/10 19:09:22 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	strchr_count(char *str, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

char	*px_barjoin(char *path, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (path && path[++i] != '\0')
		str[i] = path[i];
	while (buf && buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	return (str);
}

char	*px_strjoin(char *path, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (path && path[++i] != '\0')
		str[i] = path[i];
	while (buf && buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(path);
	return (str);
}

char	*px_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	j;
	size_t	len;
	char	*res;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_strchr(set, s1[len - 1]))
		len--;
	res = (char *)malloc(sizeof(char) * ((len - start) + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (start < len)
	{
		res[j] = s1[start];
		j++;
		start++;
	}
	res[j] = '\0';
	free(s1);
	return (res);
}
