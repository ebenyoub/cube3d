/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:27 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 17:13:42 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		go_loop(all_t *a)
{
	key_read(a);
	if (a->k.esc == 1)
		key_close(a);
	if (a->k.m == 1)
	{
		ray_launch(a);
		map_to_img(a);
		mlx_put_image_to_window(a->w.mlx, a->w.win, a->i[0].img_ptr, 0, 0);
	}
	else if (!a->m.option)
	{
		ray_launch(a);
		mlx_put_image_to_window(a->w.mlx, a->w.win, a->i[0].img_ptr, 0, 0);
	}
	return (0);
}

int		go_parsing(all_t *a)
{
	init_all(a);
	map_read(a);
	if (!init_win(a))
		m_exit(8, a);
	return (1);
}

int		go_option(all_t *a)
{
	if (a->m.option)
	{
		if (!save_bmp(a))
			return (0);
		m_exit(9, a);
	}
	a->m.parse = 1;
	if (!(a->w.win = mlx_new_window
		(a->w.mlx, a->m.width, a->m.height, "cub3d")))
		m_exit(65, a);
	mlx_hook(a->w.win, 2, 1L << 0, key_hold, a);
	mlx_hook(a->w.win, 3, 1L << 1, key_release, a);
	mlx_hook(a->w.win, 33, 1L << 17, key_close, a);
	mlx_loop_hook(a->w.mlx, go_loop, a);
	mlx_loop(a->w.mlx);
	return (1);
}

int		main(int argc, char **argv)
{
	all_t		a;

	scan_param(argc, argv, &a);
	a.m.name = argv[1];
	cub_fault(argc, argv, &a);
	if (!go_parsing(&a))
		m_exit(10, &a);
	if (!go_option(&a))
		m_exit(12, &a);
	return (EXIT_SUCCESS);
}
