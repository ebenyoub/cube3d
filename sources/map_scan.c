/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:22:14 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/04 14:59:04 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    map_scan(char *line, all_t *a)
{
	int i;
	char *nline;

	nline = NULL;
	i = 0;
	pass_space(&i, line);
	if (line[i] == '1')
		a->m.map_line = 1;
	if (a->m.map_line == 0)
	{
		if (line[0])
		{
			if (!(nline = ft_strdup(back_space(line))))
				m_exit(15);
			check_element(nline, a);
			map_data(nline, a);
		}
	}
	else if (a->m.map_line == 1)
	{
		int d;

		d = 0;
		if (!line[0])
			m_exit(6);
		if (line[i] != '1')
			m_exit(45);
		if (!(nline = ft_strdup(back_space(line))))
			m_exit(16);
		while (nline[d])
		{
			if (ft_isstr(nline[d], "120NSEW \t"))
				d++;
			else
				m_exit(5);
		}
		map_save(line, a);
	}
}