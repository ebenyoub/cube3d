/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_ceilling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:51:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/03 14:53:47 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tex_ceilling_draw(int x, int y, all_t *a)
{
	while (x < a->m.width)
	{
		a->c.cellX = (int)(a->c.floorX);
		a->c.cellY = (int)(a->c.floorY);
		a->c.tx = (int)(a->i[7].texWidth * (a->c.floorX - a->c.cellX)) &
				(a->i[7].texWidth - 1);
		a->c.ty = (int)(a->i[7].texHeight * (a->c.floorY - a->c.cellY)) &
				(a->i[7].texHeight - 1);
		a->c.floorX = a->c.floorX + a->c.floorStepX;
		a->c.floorY = a->c.floorY + a->c.floorStepY;
		if (a->m.ftex_on)
		{
			a->m.w = a->i[7].img_data[a->i[7].texWidth * a->c.ty + a->c.tx];
			a->i[0].img_data[x + (a->m.height - y - 1)
				* a->i[0].size_line / 4] = a->m.w;
		}
		else
			a->i[0].img_data[x + y * a->i[0].size_line / 4] = a->m.f;
		x++;
	}
}

void	tex_ceilling(all_t *a)
{
	int		x;
	int		y;

	y = a->m.height / 2;
	while (y < a->m.height)
	{
		x = 0;
		a->c.rayDirX0 = a->r.dirX - a->r.planX;
		a->c.rayDirY0 = a->r.dirY - a->r.planY;
		a->c.rayDirX1 = a->r.dirX + a->r.planX;
		a->c.rayDirY1 = a->r.dirY + a->r.planY;
		a->c.p = y - a->m.height / 2;
		a->c.posZ = (double)0.5 * a->m.height;
		a->c.rowDistance = a->c.posZ / a->c.p;
		a->c.floorStepX = a->c.rowDistance *
						(a->c.rayDirX1 - a->c.rayDirX0) /
						(float)a->m.width;
		a->c.floorStepY = a->c.rowDistance *
						(a->c.rayDirY1 - a->c.rayDirY0) /
						(float)a->m.width;
		a->c.floorX = a->r.posX + a->c.rowDistance * a->c.rayDirX0;
		a->c.floorY = a->r.posY + a->c.rowDistance * a->c.rayDirY0;
		tex_ceilling_draw(x, y, a);
		y += 1;
	}
}
