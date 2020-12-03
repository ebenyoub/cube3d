/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:36:03 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:21:52 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ps[i] = '\0';
		i++;
	}
}
