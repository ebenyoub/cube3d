/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:52:12 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_cub.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
