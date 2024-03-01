/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:30:04 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/09 21:59:53 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_aux(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_aux(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_aux(s1[end -1], set))
		end--;
	str = ft_substr(s1, start, end - start);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + start), end - start + 1);
	return (str);
}

/*int	main(void)
{
	char	s1[27] = "lorem ipsum dolor sit amet";
	char	set[25] = "lorem ipsum dolor sit am";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
