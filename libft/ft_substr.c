/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:27:06 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/07 17:55:43 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	size_t		i;
	char		*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main(void)
{
	char *s = "Hola Yasmin";
	char *ptr = ft_substr(s, 0, 5);
	printf("%s\n", ptr);
	return (0);
}*/