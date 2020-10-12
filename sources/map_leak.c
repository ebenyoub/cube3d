/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:53:58 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/13 01:06:37 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		map_hole(all_t *a)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < a->m.map_h)
	{
		x = -1;
		while (++x < (int)ft_strlen(a->m.map_test[y]))
		{
			if (a->m.map_test[y][x] == 'X')
			{
				if (!ft_isstr(a->m.map_test[y][x - 1], "X1") ||
					!ft_isstr(a->m.map_test[y][x + 1], "X1") ||
					!ft_isstr(a->m.map_test[y - 1][x], "X1") ||
					!ft_isstr(a->m.map_test[y + 1][x], "X1"))
					return (0);
			}
		}
	}
	return (1);
}

int		map_leak_x(int x, int y, all_t *a)
{
	if (x - 1 >= 0 && a->m.map_test[y][x - 1] != '1'
		&& a->m.map_test[y][x - 1] != 'X' && a->m.map_test[y][x - 1] != ' ')
	{
		a->m.map_test[y][x - 1] = 'X';
		map_leak_y(x - 1, y, a);
	}
	if (a->m.map_test[y][x + 1] != '1' && a->m.map_test[y][x + 1] != 'X'
		&& a->m.map_test[y][x + 1] != '\0' && a->m.map_test[y][x + 1] != ' ')
	{
		a->m.map_test[y][x + 1] = 'X';
		map_leak_y(x + 1, y, a);
	}
	return (0);
}

int		map_leak_y(int x, int y, all_t *a)
{
	if (y - 1 >= 0 && x < (int)ft_strlen(a->m.map_test[y - 1])
		&& a->m.map_test[y - 1][x] != '1' && a->m.map_test[y - 1][x] != 'X'
		&& a->m.map_test[y - 1][x] != ' ')
	{
		a->m.map_test[y - 1][x] = 'X';
		map_leak_y(x, y - 1, a);
	}
	if (y + 1 < a->m.map_h && x < (int)ft_strlen(a->m.map_test[y + 1])
		&& a->m.map_test[y + 1][x] != '1' && a->m.map_test[y + 1][x] != 'X'
		&& a->m.map_test[y + 1][x] != ' ')
	{
		a->m.map_test[y + 1][x] = 'X';
		map_leak_y(x, y + 1, a);
	}
	map_leak_x(x, y, a);
	return (0);
}

void	map_leak(int x, int y, all_t *a)
{
	map_leak_y(x, y, a);
	if (!map_hole(a))
		ret_exit("Error\nMap format is not accepted.");
}
