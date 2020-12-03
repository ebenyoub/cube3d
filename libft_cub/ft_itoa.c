/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:38:16 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:33:46 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

static int		len_nb(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*convert(char *str, long nb, int len)
{
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	else if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		while (len > 0)
		{
			str[len--] = 48 + (nb % 10);
			nb /= 10;
		}
	}
	else
	{
		while (len >= 0)
		{
			str[len--] = 48 + (nb % 10);
			nb /= 10;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = len_nb(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	return (convert(str, nb, len));
}
