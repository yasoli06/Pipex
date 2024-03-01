/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:13:13 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/06 15:46:59 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < dstsize -1 && src[i] != '\0')
	{
		dest[i] = src [i];
		i++;
	}
	if (i < dstsize)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int main(void)
{
	char str[] = "1234567890";
	char str2[] = "1234567890";
	unsigned int a;
	unsigned int b;

	a = ft_strlcpy(str, str2, 5);
	b = strlcpy(str, str2, 5);
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
*/
