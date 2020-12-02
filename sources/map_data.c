/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:53:42 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 11:03:18 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resolution(all_t *a)
{
	if (a->m.width > 1395)
		a->m.width = 1395;
	if (a->m.width < 100)
		a->m.width = 100;
	if (a->m.height > 845)
		a->m.height = 845;
	if (a->m.height < 100)
		a->m.height = 100;
}

void	intruder_map(char *line)
{
	if ((line[0] == 'N' && line[1] != 'O') ||
		(line[0] == 'W' && line[1] != 'E') ||
		(line[0] == 'E' && line[1] != 'A') ||
		(line[0] == 'R' && line[1] != ' ') ||
		(line[0] == 'F' && line[1] != ' ') ||
		(line[0] == 'C' && line[1] != ' '))
		m_exit(23);
}

void	map_data_three(char *line, all_t *a)
{
	int i;

	i = 1;
	if (line[0] == 'E' && line[1] == 'A')
	{
		if (!(a->m.img[3] = ft_strdup(map_cut(line))))
			m_exit(20);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		if (!(a->m.img[4] = ft_strdup(map_cut(line))))
			m_exit(21);
	}
	else if (line[0] == 'F')
	{
		pass_space(&i, line);
		if (!ft_strncmp(line + i, "ressources/pokemon", 18))
			m_exit(63);
		if (!(a->m.img[5] = ft_strdup(map_cut(line))))
			m_exit(22);
	}
	else if (line[0] == 'C')
		a->m.c = map_color(map_cut(line));
}

void	map_data_next(char *line, all_t *a)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (!(a->m.img[0] = ft_strdup(map_cut(line))))
			m_exit(17);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (!(a->m.img[1] = ft_strdup(map_cut(line))))
			m_exit(18);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (!(a->m.img[2] = ft_strdup(map_cut(line))))
			m_exit(19);
	}
	else
		map_data_three(line, a);
}

void	map_data(char *line, all_t *a)
{
	int i;

	i = 2;
	intruder_map(line);
	if (!ft_isstr(line[0], "RNSWEFC"))
		m_exit(23);
	if (line[0] == 'R')
	{
		pass_space(&i, line);
		while (ft_isdigit(line[i]))
			a->m.width = a->m.width * 10 + (line[i++] - 48);
		pass_space(&i, line);
		while (ft_isdigit(line[i]))
			a->m.height = a->m.height * 10 + (line[i++] - 48);
		resolution(a);
		pass_space(&i, line);
		if (line[i])
			m_exit(61);
	}
	map_data_next(line, a);
}
