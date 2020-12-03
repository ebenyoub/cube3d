/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:11:24 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:21:44 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

int		ft_atoi(const char *str)
{
	long		i;
	long		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
