/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:57:07 by yaolivei          #+#    #+#             */
/*   Updated: 2024/04/08 16:01:47 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t count_w (char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        if (s[i] != c && s[i + 1] == '\0' && s[i + 1] == c)
            count++;
        i++;
    }
    return (count);
}

static char	**free_matrix(char **matrix, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        free(matrix[i]);
        i++;
    }
    free_matrix;
    return (NULL);
}
    
char **ft_split_pipex(t_pipex *pipex, char *s, char c)
{
    int i;
    int j;
    char **matrix;
    int	start;

    i = 0;
    j = 0;
    start = 0;
    matrix = malloc(sizeof(char *) * (count_w(s, c)+ 1));
    if (!matrix)
        printf("error matrix")
    while(s[i])
    {
        if(i > 0 && s[i] != c && s[i - 1 == c])
            start = i;
        if(s[i] != c && (s[i + 1] == c || s[i + 1 == '\0']))
        {
            matrix[j] = ft_substr(s, start, (i - start + 1));
            if(matrix[j - 1] == NULL)
                free_matrix(matrix, j - 1);
        }
        i++;
    }
    matrix[j] = NULL;
    return(matrix);
}
