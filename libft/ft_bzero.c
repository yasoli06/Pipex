/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:33:14 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/04 16:34:47 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*p;

	p = s;
	a = 0;
	while (a < n)
	{
		p[a] = '\0';
		a++;
	}
}

/*int main(void)
{
	char str[] = "1234567890";
	ft_bzero(str, 5);
	printf("%s\n", str);
	return (0);
}*/