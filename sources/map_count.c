/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:22:34 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 12:18:34 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_element(all_t *a)
{
	a->m.element[0] = 0;
	a->m.element[1] = 0;
	a->m.element[2] = 0;
	a->m.element[3] = 0;
	a->m.element[4] = 0;
	a->m.element[5] = 0;
	a->m.element[6] = 0;
	a->m.element[7] = 0;
}

void	check_element(char *line, all_t *a)
{
	if (line[0] == 'R')
		a->m.element[0] += 1;
	if (line[0] == 'N' && line[1] == 'O')
		a->m.element[1] += 1;
	if (line[0] == 'S' && line[1] != 'O')
		a->m.element[2] += 1;
	if (line[0] == 'S' && line[1] == 'O')
		a->m.element[3] += 1;
	if (line[0] == 'W' && line[1] == 'E')
		a->m.element[4] += 1;
	if (line[0] == 'E' && line[1] == 'A')
		a->m.element[5] += 1;
	if (line[0] == 'F')
		a->m.element[6] += 1;
	if (line[0] == 'C')
		a->m.element[7] += 1;
}

void	verif_nb_next(all_t *a)
{
	if (a->m.element[0] <= 0)
		m_exit(35, a);
	if (a->m.element[1] <= 0)
		m_exit(36, a);
	if (a->m.element[2] <= 0)
		m_exit(37, a);
	if (a->m.element[3] <= 0)
		m_exit(38, a);
	if (a->m.element[4] <= 0)
		m_exit(39, a);
	if (a->m.element[5] <= 0)
		m_exit(40, a);
	if (a->m.element[6] <= 0)
		m_exit(41, a);
	if (a->m.element[7] <= 0)
		m_exit(42, a);
}

void	verif_nb(all_t *a)
{
	if (a->m.pos_nb == 0)
		m_exit(48, a);
	if (a->m.element[0] > 1)
		m_exit(27, a);
	if (a->m.element[1] > 1)
		m_exit(28, a);
	if (a->m.element[2] > 1)
		m_exit(29, a);
	if (a->m.element[3] > 1)
		m_exit(30, a);
	if (a->m.element[4] > 1)
		m_exit(31, a);
	if (a->m.element[5] > 1)
		m_exit(32, a);
	if (a->m.element[6] > 1)
		m_exit(33, a);
	if (a->m.element[7] > 1)
		m_exit(34, a);
	verif_nb_next(a);
}
