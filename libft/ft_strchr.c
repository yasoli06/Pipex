/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:36:18 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/04 13:30:10 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*int main() {
    char str[] = "Hello, World!";
    char *result = strchr(str, 'W');

    if (result != NULL) {
        printf("Caracter encontrado: %c\n", *result);
    } else {
        printf("Caracter no encontrado.\n");
    }

    return 0;
}*/
