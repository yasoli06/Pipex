/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:39:15 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/29 16:10:17 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*ptr;
	size_t				i;
	unsigned char		d;

	d = (unsigned char)c;
	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == d)
			return ((void *) &ptr[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char str[] = "1234567890";
	char *ptr;

	ptr = ft_memchr(str, '5', 5);
	printf("%s\n", ptr);
	return (0);
}*/