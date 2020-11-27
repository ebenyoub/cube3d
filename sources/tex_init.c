/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:17:13 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/27 18:13:28 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tex_wall(all_t *a)
{
	if (a->r.side == 1)
		a->t.texNum = a->r.rDirY < 0 ? 3 : 4;
	else
		a->t.texNum = a->r.rDirX < 0 ? 1 : 2;
	if (a->r.side == 0)
		a->t.wallX = a->r.posY + a->r.perpWallDist * a->r.rDirY;
	else
		a->t.wallX = a->r.posX + a->r.perpWallDist * a->r.rDirX;
	a->t.wallX -= floor((a->t.wallX));
	a->t.texX = (int)(a->t.wallX * (double)a->i[a->t.texNum].texWidth);
	if (a->r.side == 0 && a->r.rDirX > 0)
		a->t.texX = a->i[a->t.texNum].texWidth - a->t.texX - 1;
	if (a->r.side == 1 && a->r.rDirY > 0)
		a->t.texX = a->i[a->t.texNum].texWidth - a->t.texX - 1;
}
