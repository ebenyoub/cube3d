/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:08:00 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:37:06 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (unsigned char)c)
		if (!s[i])
			return (0);
		else
			i++;
	return ((char *)s + i);
}

int		ft_strchr_gnl(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}
