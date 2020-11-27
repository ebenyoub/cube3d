/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:53:42 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/27 17:52:03 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resolution(all_t *a)
{
	if (a->m.width > 1395)
		a->m.width = 1395;
	if (a->m.width < 100)
		a->m.width = 100;
	if (a->m.height > 872)
		a->m.height = 872;
	if (a->m.height < 62)
		a->m.height = 62;
}

void	map_data_next(char *line, all_t *a)
{
	if (line[0] == 'N')
		if (!(a->m.img[0] = ft_strdup(map_cut(line))))
			m_exit(17);
	if (line[0] == 'S' && line[1] == 'O')
		if (!(a->m.img[1] = ft_strdup(map_cut(line))))
			m_exit(18);
	if (line[0] == 'W')
		if (!(a->m.img[2] = ft_strdup(map_cut(line))))
			m_exit(19);
	if (line[0] == 'E')
		if (!(a->m.img[3] = ft_strdup(map_cut(line))))
			m_exit(20);
	if (line[0] == 'S' && line[1] == ' ')
		if (!(a->m.img[4] = ft_strdup(map_cut(line))))
			m_exit(21);
	if (line[0] == 'F')
		if (!(a->m.img[5] = ft_strdup(map_cut(line))))
			m_exit(22);
	if (line[0] == 'C')
		a->m.c = map_color(map_cut(line));
}

void	map_data(char *line, all_t *a)
{
	int i;

	i = 2;
	if (line[0] == 'R')
	{
		while (ft_isdigit(line[i]))
			a->m.width = a->m.width * 10 + (line[i++] - 48);
		while (ft_isdigit(line[++i]))
			a->m.height = a->m.height * 10 + (line[i] - 48);
		resolution(a);
	}
	map_data_next(line, a);
}
