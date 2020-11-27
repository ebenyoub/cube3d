/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:32:37 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/09 17:34:38 by ebenyoub         ###   ########lyon.fr   */
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
	if (c == 'N')
	{
		a->r.planX = 0;
		a->r.planY = 0.66;
	}
	if (c == 'S')
	{
		a->r.planX = 0;
		a->r.planY = -0.66;
	}
	if (c == 'W')
	{
		a->r.planX = -0.66;
		a->r.planY = 0;
	}
	if (c == 'E')
	{
		a->r.planX = 0.66;
		a->r.planY = 0;
	}
}
