/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:31:15 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:38:46 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(str = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len && s[start + i] && ft_strlen(s) > start)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
