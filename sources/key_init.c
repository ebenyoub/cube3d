/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:24:37 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/19 14:57:53 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_close(all_t *a)
{
	mlx_destroy_window(a->w.mlx, a->w.win);
	ft_putstr("Cub3d by ebenyoub.\n");
	exit(EXIT_SUCCESS);
}

int		key_hold(int key, all_t *a)
{
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 1;
	if (key == KEY_Q)
		a->k.q = 1;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 1;
	if (key == KEY_D)
		a->k.d = 1;
	if (key == ARROW_LEFT)
		a->k.al = 1;
	if (key == ARROW_RIGHT)
		a->k.ar = 1;
	if (key == KEY_M)
		a->k.m = 1;
	if (key == KEY_L)
		a->k.m = 1;
	if (key == KEY_ESC)
		a->k.esc = 1;
	return (0);
}

int		key_release(int key, all_t *a)
{
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 0;
	if (key == KEY_Q)
		a->k.q = 0;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 0;
	if (key == KEY_D)
		a->k.d = 0;
	if (key == ARROW_LEFT)
		a->k.al = 0;
	if (key == ARROW_RIGHT)
		a->k.ar = 0;
	if (key == KEY_M)
		a->k.m = 0;
	if (key == KEY_L)
		a->k.m = 0;
	if (key == KEY_ESC)
		a->k.esc = 0;
	return (0);
}
