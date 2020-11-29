/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:10:58 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/29 10:24:40 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_vertical(all_t *a)
{
	if (a->k.z == 1)
	{
		if (!ft_isstr((a->m.map_tab[(int)(a->r.posX + a->r.dirX\
		* a->f.moveSpeed)][(int)a->r.posY]), "12"))
			a->r.posX += a->r.dirX * a->f.moveSpeed;
		if (!ft_isstr((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		+ a->r.dirY * a->f.moveSpeed)]), "12"))
			a->r.posY += a->r.dirY * a->f.moveSpeed;
	}
	if (a->k.s == 1)
	{
		if (!ft_isstr((a->m.map_tab[(int)(a->r.posX - a->r.dirX\
		* a->f.moveSpeed)][(int)a->r.posY]), "12"))
			a->r.posX -= a->r.dirX * a->f.moveSpeed;
		if (!ft_isstr((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		- a->r.dirY * a->f.moveSpeed)]), "12"))
			a->r.posY -= a->r.dirY * a->f.moveSpeed;
	}
}

void	key_horizontal(all_t *a)
{
	if (a->k.d == 1)
	{
		if (!ft_isstr((a->m.map_tab[(int)(a->r.posX + a->r.planX\
		* a->f.moveSpeed)][(int)a->r.posY]), "12"))
			a->r.posX += a->r.planX * a->f.moveSpeed;
		if (!ft_isstr((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		+ a->r.planY * a->f.moveSpeed)]), "12"))
			a->r.posY += a->r.planY * a->f.moveSpeed;
	}
	if (a->k.q == 1)
	{
		if (!ft_isstr((a->m.map_tab[(int)(a->r.posX - a->r.planX\
		* a->f.moveSpeed)][(int)a->r.posY]), "12"))
			a->r.posX -= a->r.planX * a->f.moveSpeed;
		if (!ft_isstr((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		- a->r.planY * a->f.moveSpeed)]), "12"))
			a->r.posY -= a->r.planY * a->f.moveSpeed;
	}
}

void	key_rotation_al(all_t *a)
{
	if (a->k.al == 1)
	{
		a->f.oldDirX = a->r.dirX;
		a->r.dirX = a->r.dirX * cos(a->f.rotSpeed) - a->r.dirY\
							* sin(a->f.rotSpeed);
		a->r.dirY = a->f.oldDirX * sin(a->f.rotSpeed) + a->r.dirY\
								* cos(a->f.rotSpeed);
		a->f.oldPlanX = a->r.planX;
		a->r.planX = a->r.planX * cos(a->f.rotSpeed) - a->r.planY\
								* sin(a->f.rotSpeed);
		a->r.planY = a->f.oldPlanX * sin(a->f.rotSpeed) + a->r.planY\
								* cos(a->f.rotSpeed);
	}
}

void	key_rotation_ar(all_t *a)
{
	if (a->k.ar == 1)
	{
		a->f.oldDirX = a->r.dirX;
		a->r.dirX = a->r.dirX * cos(-a->f.rotSpeed) - a->r.dirY\
							* sin(-a->f.rotSpeed);
		a->r.dirY = a->f.oldDirX * sin(-a->f.rotSpeed) + a->r.dirY\
								* cos(-a->f.rotSpeed);
		a->f.oldPlanX = a->r.planX;
		a->r.planX = a->r.planX * cos(-a->f.rotSpeed) - a->r.planY\
								* sin(-a->f.rotSpeed);
		a->r.planY = a->f.oldPlanX * sin(-a->f.rotSpeed) + a->r.planY\
								* cos(-a->f.rotSpeed);
	}
}

int		key_read(all_t *a)
{
	key_vertical(a);
	key_horizontal(a);
	key_rotation_ar(a);
	key_rotation_al(a);
	tex_floor(a);
	if (a->k.esc == 1)
	{
		key_close(a);
	}
	if (a->k.m == 1)
	{
		ray_launch(a);
		map_to_img(a);
		mlx_put_image_to_window(a->w.mlx, a->w.win, a->i[0].img_ptr, 0, 0);
	}
	else
	{
		ray_launch(a);
		mlx_put_image_to_window(a->w.mlx, a->w.win, a->i[0].img_ptr, 0, 0);
	}
	return (0);
}
