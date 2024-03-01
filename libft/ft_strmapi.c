/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:32:17 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/06 15:56:46 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len_s;
	char	*ptr;
	int		i;

	if (!s || !f)
	len_s = ft_strlen(s);
		return (NULL);
	ptr = (char *)malloc(len_s + 1);
	if (!ptr)
		return (NULL);
	ptr[len_s] = '\0';
	i = 0;
	while (i < len_s)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
