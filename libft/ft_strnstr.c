/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:23:37 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/04 17:02:32 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(needle);
	if (j == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + j <= len)
	{
		if (strncmp(&haystack[i], needle, j) == 0)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main()
{
	const char	*haystack = "CASA";
	const char	*needle = "ASA";
}
*/