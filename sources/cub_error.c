/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:17:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/09 17:18:18 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		cub_fault(int argc)
{
	if (argc != 2)
	{
		write(1, ":: Choose the map's path...\n", 29);
		write(1, ":: ./cub3d source/map.cub", 25);
		return (1);
	}
	return (0);
}

void	ret_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}
