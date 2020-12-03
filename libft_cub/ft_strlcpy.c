/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:57:49 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:37:55 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	if (dst && src)
	{
		srclen = ft_strlen(src);
		if (srclen < size)
			ft_memcpy(dst, src, srclen + 1);
		else if (size != 0)
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
		return (srclen);
	}
	return (0);
}
