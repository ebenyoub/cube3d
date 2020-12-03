/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:55:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:35:40 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src && n)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}
