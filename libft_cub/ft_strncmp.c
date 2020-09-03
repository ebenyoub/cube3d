/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:06:20 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_cub.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while ((d[i] || s[i]) && (n-- > 0))
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		else
			i++;
	}
	return (0);
}
