/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:19:46 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/09 17:01:06 by yaolivei         ###   ########.fr       */
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
	return(n);
}

char	*px_barjoin(char *path, char *buf)
{
	size_t	i;
	size_t	j;
	char *str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while(path && path[++i] != '\0')
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
	char *str;

	i = 0;
	str = malloc(sizeof(char) * ((ft_strlen(path) + ft_strlen(buf)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while(path && path[++i] != '\0')
		str[i] = path[i];
	while (buf && buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(path);
	return (str);
}
