/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:24:37 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/30 13:01:02 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_close(all_t *a)
{
	mlx_destroy_window(a->w.mlx, a->w.win);
	r_exit(58, a);
	return (0);
}

int		key_hold(int key, all_t *a)
{
	if (key == K_Z || key == K_ARROW_UP)
		a->k.z = 1;
	if (key == K_Q)
		a->k.q = 1;
	if (key == KEY_S || key == K_ARROW_DOWN)
		a->k.s = 1;
	if (key == K_D)
		a->k.d = 1;
	if (key == K_ARROW_LEFT)
		a->k.al = 1;
	if (key == K_ARROW_RIGHT)
		a->k.ar = 1;
	if (key == K_M || key == K_L || key == 46)
		a->k.m = 1;
	if (key == K_L)
		a->k.m = 1;
	if (key == K_ESCAPE)
		a->k.esc = 1;
	return (0);
}

int		key_release(int key, all_t *a)
{
	if (key == K_Z || key == K_ARROW_UP)
		a->k.z = 0;
	if (key == K_Q)
		a->k.q = 0;
	if (key == KEY_S || key == K_ARROW_DOWN)
		a->k.s = 0;
	if (key == K_D)
		a->k.d = 0;
	if (key == K_ARROW_LEFT)
		a->k.al = 0;
	if (key == K_ARROW_RIGHT)
		a->k.ar = 0;
	if (key == K_M || key == K_L || key == 46)
		a->k.m = 0;
	if (key == K_L)
		a->k.m = 0;
	if (key == K_ESCAPE)
		a->k.esc = 0;
	return (0);
}
