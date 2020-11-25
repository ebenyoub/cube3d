/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:27 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/04 10:26:55 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		go_parsing(all_t *a)
{
	init_all(a);
	map_read(a);
	if (!init_win(a))
		m_exit(8);
	return (1);
}

int		go_option(all_t *a)
{
	if (a->m.option)
	{
		if (!save_bmp(a))
			return (0);
		m_exit(9);
	}
	else
	{
		mlx_hook(a->w.win, 2, 1L << 0, key_hold, a);
		mlx_hook(a->w.win, 3, 1L << 1, key_release, a);
		mlx_hook(a->w.win, 17, 1L << 17, key_close, a);
		mlx_loop_hook(a->w.mlx, key_read, a);
		mlx_loop(a->w.mlx);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	all_t		a;

	scan_param(argc, argv, &a);
	a.m.name = argv[1];
	cub_fault(argc, argv);
	if (!go_parsing(&a))
		m_exit(10);
	if (!go_option(&a))
		m_exit(12);
	return (EXIT_SUCCESS);
}
