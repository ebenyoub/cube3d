/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:32:37 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/29 13:11:20 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_dir(char c, all_t *a)
{
	if (c == 'N')
	{
		a->r.dirX = -1;
		a->r.dirY = 0;
	}
	if (c == 'S')
	{
		a->r.dirX = 1;
		a->r.dirY = 0;
	}
	if (c == 'E')
	{
		a->r.dirX = 0;
		a->r.dirY = 1;
	}
	if (c == 'W')
	{
		a->r.dirX = 0;
		a->r.dirY = -1;
	}
}

void	map_plan(char c, all_t *a)
{
	double p;

	p = (double)a->m.width / (double)a->m.height * 0.66 / 1.6;
	if (c == 'N')
	{
		a->r.planX = 0;
		a->r.planY = p;
	}
	if (c == 'S')
	{
		a->r.planX = 0;
		a->r.planY = -p;
	}
	if (c == 'W')
	{
		a->r.planX = -p;
		a->r.planY = 0;
	}
	if (c == 'E')
	{
		a->r.planX = p;
		a->r.planY = 0;
	}
}
