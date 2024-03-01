/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:09:21 by yaolivei          #+#    #+#             */
/*   Updated: 2024/02/29 16:11:58 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char	*a;
	const char	*b;

	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str1[] = "1234567890";
	char str2[] = "1234567890";
	int a;

	a = ft_memcmp(str1, str2, 10);
	printf("%d\n", a);
	return (0);
}*/
