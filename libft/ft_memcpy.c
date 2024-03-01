/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:26:13 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/27 15:38:46 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char str[] = "1234567890";
	char str2[] = "1234567890";
	char *ptr;
	char *ptr2;

	ptr = ft_memcpy(str, str2, 5);
	ptr2 = memcpy(str, str2, 5);
	printf("%s\n", ptr);
	printf("%s\n", ptr2);
	return (0);
}*/