/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 01:12:36 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/06 15:56:39 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
/*int main
{
	char str[] = "1234567890";
	char *ptr;

	ptr = ft_strrchr(str, '5');
	printf("%s\n", ptr);
	return (0);
}
*/