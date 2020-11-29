/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:16:01 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/29 18:08:27 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map(all_t *a)
{
	a->m.width = 0;
	a->m.height = 0;
	a->m.map_h = 0;
	a->m.map_w = 0;
	a->t.tmp_x = 0;
	a->t.tmp_y = 0;
	a->s.spr_nbr = 0;
	a->m.map_tab = NULL;
	a->m.map_count = 0;
	a->m.save = 0;
	a->m.map_line = 0;
	if (!(a->m.map = ft_strdup("")))
		m_exit(49);
	a->f.moveSpeed = 0.08;
	a->f.rotSpeed = 0.06;
	a->m.map_size_x = 0;
	a->m.pos_nb = 0;
}

void	init_ray(all_t *a)
{
	a->r.mapX = 0;
	a->r.mapY = 0;
	a->r.posX = 0;
	a->r.posY = 0;
	a->r.dirX = 0;
	a->r.dirY = 0;
	a->r.planX = 0;
	a->r.planY = 0;
	a->r.camX = 0;
	a->r.rDirX = 0;
	a->r.rDirY = 0;
	a->r.hit = 0;
	a->r.perpWallDist = 0;
	a->r.deltaDistX = 0;
	a->r.deltaDistY = 0;
	a->r.drawEnd = 0;
	a->r.drawStart = 0;
	a->r.side = 0;
	a->s.vMoveScreen = 0;
}

void	init_keycode(all_t *a)
{
	a->k.z = 0;
	a->k.s = 0;
	a->k.q = 0;
	a->k.d = 0;
	a->k.m = 0;
	a->k.l = 0;
	a->k.al = 0;
	a->k.ar = 0;
	a->k.esc = 0;
	a->k.lock = 0;
}

void	init_all(all_t *a)
{
	init_map(a);
	init_ray(a);
	init_keycode(a);
	init_element(a);
}
