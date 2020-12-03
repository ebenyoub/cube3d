/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:53:42 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/03 16:21:57 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_data_three(char *line, all_t *a)
{
	int i;

	i = 1;
	if (line[0] == 'E' && line[1] == 'A')
	{
		if (!(a->m.img[3] = ft_strdup(map_cut(line, a))))
			m_exit(20, a);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		if (!(a->m.img[4] = ft_strdup(map_cut(line, a))))
			m_exit(21, a);
	}
	map_f(line, a);
}

void	map_data_next(char *line, all_t *a)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (!(a->m.img[0] = ft_strdup(map_cut(line, a))))
			m_exit(17, a);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (!(a->m.img[1] = ft_strdup(map_cut(line, a))))
			m_exit(18, a);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (!(a->m.img[2] = ft_strdup(map_cut(line, a))))
			m_exit(19, a);
	}
	else
		map_data_three(line, a);
}

void	r_negative(int *res, int *e, char *line, all_t *a)
{
	long	l;
	int		i;

	l = 0;
	i = *e;
	while (ft_isdigit(line[i]))
		l = l * 10 + (line[i++] - 48);
	if (l > 2147483647)
		m_exit(67, a);
	else
		*res = (int)l;
	*e = i;
}

void	r_save(int *e, char *line, all_t *a)
{
	int r;
	int i;

	r = 0;
	i = *e;
	if (line[i] == '-')
		m_exit(66, a);
	if (ft_isdigit(line[i]))
	{
		r_negative(&a->m.width, &i, line, a);
		r++;
	}
	pass_space(&(i), line);
	if (line[i] == '-')
		m_exit(66, a);
	if (ft_isdigit(line[i]))
	{
		r_negative(&a->m.height, &i, line, a);
		r++;
	}
	if (r != 2)
		m_exit(61, a);
	*e = i;
}

void	map_data(char *line, all_t *a)
{
	int i;

	i = 1;
	intruder_map(line, a);
	if (!ft_isstr(line[0], "RNSWEFC"))
		m_exit(23, a);
	if (line[0] == 'R')
	{
		pass_space(&i, line);
		r_save(&i, line, a);
		resolution(a);
		pass_space(&i, line);
		if (line[i])
			m_exit(61, a);
	}
	map_data_next(line, a);
}
