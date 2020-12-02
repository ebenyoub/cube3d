/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:22:14 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 12:20:49 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	post_scan(int *i, char *line, all_t *a)
{
	int		d;
	char	*nline;

	d = 0;
	if (!line[0])
		m_exit(6, a);
	if (ft_isstr(line[*i], "NSEW"))
		m_exit(59, a);
	if (!ft_isstr(line[*i], "12"))
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
