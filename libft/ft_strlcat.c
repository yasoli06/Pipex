/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:18:17 by yaolivei          #+#    #+#             */
/*   Updated: 2023/09/25 04:09:47 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	if (dstsize == 0 || len_dst > dstsize)
		return (len_src + dstsize);
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

/*int	main()
{
	char	src[] = " tal? como estas?";
	char	dst[40] = "Hola que";
	char	src2[] = " tal? como estas?";
	char	dst2[40] = "Hola que";
	int a;
	int b;
	size_t	dstsize;

	dstsize = 40;
	a = ft_strlcat(dst, src, dstsize);
	printf("Result mi strlcat: |%s|\n", dst);
	printf("mia deveulve: %d\n", a);
	b = strlcat(dst2, src2, dstsize);
	printf("Result strlcat original: |%s|\n", dst2);
	printf("original deveulve: %d\n", b);
	return (0);
}*/
