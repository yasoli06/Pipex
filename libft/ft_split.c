/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:37:05 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/29 15:54:33 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (count);
}

static char	**free_matrix(char **matrix, int num_col)
{
	int	i;

	i = 0;
	while (i < num_col)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	matrix = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!matrix)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			matrix[j++] = ft_substr(s, start, (i - start +1));
			if (matrix[j - 1] == NULL)
				return (free_matrix(matrix, j - 1));
		}
		i++;
	}
	matrix[j] = NULL;
	return (matrix);
}
/*int main()
{
	char **splitted;
	int i;

	i = 0;
	splitted = ft_split("hola que tal como estas tu", ' ');
	while(splitted[i] != NULL)
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	return(1);

}*/