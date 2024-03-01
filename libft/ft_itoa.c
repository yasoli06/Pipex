/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaolivei <yaolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:42:19 by yaolivei          #+#    #+#             */
/*   Updated: 2023/10/06 22:51:45 by yaolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contar_digitos(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_numero_absoluto(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_contar_digitos(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[--len] = ft_numero_absoluto(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*int main()
{
	int n = -150;
	printf("%s", ft_itoa(n));
}*/