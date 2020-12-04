/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:22:14 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/04 12:01:39 by ebenyoub         ###   ########lyon.fr   */
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

void	intruder_map(char *line, all_t *a)
{
	if ((line[0] == 'N' && line[1] != 'O') ||
		(line[0] == 'W' && line[1] != 'E') ||
		(line[0] == 'E' && line[1] != 'A') ||
		(line[0] == 'R' && line[1] != ' ') ||
		(line[0] == 'F' && line[1] != ' ') ||
		(line[0] == 'C' && line[1] != ' '))
		m_exit(23, a);
}

void	post_scan(int *i, char *line, all_t *a)
{
	int		d;
	char	*nline;

	d = 0;
	if (!line[0] && a->m.ret_line)
		m_exit(6, a);
	if (ft_isstr(line[*i], "NSEW"))
		m_exit(59, a);
	if (!ft_isstr(line[*i], "12") && a->m.ret_line)
		m_exit(45, a);
	nline = back_space(line);
	while (nline[d])
	{
		if (ft_isstr(nline[d], "120NSEW \t"))
			d++;
		else
			m_exit(5, a);
		if (nline[0] == '2')
			m_exit(64, a);
	}
	map_save(line, a);
}

void	pre_scan(char *line, all_t *a)
{
	char *nline;

	nline = NULL;
	if (line[0])
	{
		nline = back_space(line);
		check_element(nline, a);
		map_data(nline, a);
	}
}

void	map_scan(char *line, all_t *a)
{
	int i;

	i = 0;
	pass_space(&i, line);
	if (line[i] == '1')
		a->m.map_line = 1;
	if (a->m.map_line == 0)
		pre_scan(line, a);
	else if (a->m.map_line == 1)
		post_scan(&i, line, a);
}
