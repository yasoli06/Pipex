/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:45:50 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/04 16:36:27 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len-- > 0)
		{
			*d-- = *s--;
		}
	}
	else
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}

/*int main(void)
{
	char str[] = "1234567890";
	char str2[] = "1234567890";
	char *ptr;
	char *ptr2;

	ptr = ft_memmove(str, str2, 5);
	ptr2 = memmove(str, str2, 5);
	printf("%s\n", ptr);
	printf("%s\n", ptr2);
	return (0);
}*/