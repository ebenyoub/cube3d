/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:53:58 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/29 12:07:44 by user42           ###   ########lyon.fr   */
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
	pass_space(&x, a->m.map_test[y]);
	if (x - 1 >= 0 && !ft_isstr(a->m.map_test[y][x - 1], "X1"))
	{
		if (ft_isstr(a->m.map_test[y][x - 1], " \t"))
			m_exit(44);
		else if (!ft_isstr(a->m.map_test[y][x - 1], "120NSEW"))
			m_exit(5);
		else
			a->m.map_test[y][x - 1] = 'X';
		map_leak_y(x - 1, y, a);
	}
	if (x + 1 < (int)ft_strlen(a->m.map_test[y])
		&& !ft_isstr(a->m.map_test[y][x + 1], "X1"))
	{
		if (ft_isstr(a->m.map_test[y][x + 1], " \t"))
			m_exit(44);
		else if (!ft_isstr(a->m.map_test[y][x + 1], "120NSEW"))
			m_exit(5);
		else
			a->m.map_test[y][x + 1] = 'X';
		map_leak_y(x + 1, y, a);
	}
	return (0);
}

int		map_leak_y(int x, int y, all_t *a)
{
	pass_space(&x, a->m.map_test[y]);
	if (y - 1 >= 0 && x < (int)ft_strlen(a->m.map_test[y - 1])
		&& !ft_isstr(a->m.map_test[y - 1][x], "X1"))
	{
		if (ft_isstr(a->m.map_test[y - 1][x], " \t"))
			m_exit(44);
		else if (!ft_isstr(a->m.map_test[y - 1][x], "120NSEW"))
			m_exit(5);
		else
			a->m.map_test[y - 1][x] = 'X';
		map_leak_y(x, y - 1, a);
	}
	if (y + 1 < a->m.map_h && x < (int)ft_strlen(a->m.map_test[y + 1])
		&& !ft_isstr(a->m.map_test[y + 1][x], "X1"))
	{
		if (ft_isstr(a->m.map_test[y + 1][x], " \t"))
			m_exit(44);
		else if (!ft_isstr(a->m.map_test[y + 1][x], "120NSEW"))
			m_exit(5);
		else
			a->m.map_test[y + 1][x] = 'X';
		map_leak_y(x, y + 1, a);
	}
	map_leak_x(x, y, a);
	return (0);
}

void	map_leak(int x, int y, all_t *a)
{
	a->m.map_test = ft_split(a->m.map, '|');
	if (y == 0 && ft_isstr(a->m.map_test[y][x], "NSEW"))
		m_exit(59);
	map_leak_y(x, y, a);
	if (a->m.map_test[y][x] != 'X')
		m_exit(59);
	if (!map_hole(a))
		m_exit(4);
	tab_free(a->m.map_test);
}
