/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:27 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/09 17:20:11 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	all_t		a;
	int			wa;

	if (cub_fault(argc))
		return (EXIT_FAILURE);
	a.m.name = argv[1];
	init_all(&a);
	map_read(&a);
	wa = init_win(&a);
	if (wa != 0)
		ret_exit("une erreur est survenue\n");
	mlx_hook(a.w.win, 2, 0, key_hold, &a);
	mlx_hook(a.w.win, 3, 0, key_release, &a);
	mlx_hook(a.w.win, 17, 0, key_close, &a);
	mlx_loop_hook(a.w.mlx, key_read, &a);
	mlx_loop(a.w.mlx);
	return (EXIT_SUCCESS);
}
