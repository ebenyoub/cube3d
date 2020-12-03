/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:50:50 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:38:29 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen((char *)haystack) < ft_strlen((char *)needle))
		return (0);
	while (haystack[i] && len--)
	{
		while ((haystack[i + j] == needle[j]) && (haystack[i + j] ||
					needle[j]) && (j <= len))
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		if (needle[j] != haystack[i])
			j = 0;
		i++;
	}
	return (0);
}
