/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:24:50 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:22:07 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	len;
	int				*area;

	len = size * count;
	if (!(area = malloc(len)))
		return (NULL);
	return (ft_memset(area, '\0', len));
}
