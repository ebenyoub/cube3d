/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:23:06 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:43:53 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isstr(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}
