/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:50:09 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:38:35 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)&s[i];
		else
			i--;
	}
	return (0);
}
