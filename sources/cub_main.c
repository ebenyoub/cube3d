/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:27 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/20 11:46:49 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		go_parsing(all_t *a)
{
	init_all(a);
	map_read(a);
	if (!init_win(a))
	{
		ft_putstr("Error\nImages Loading failure.\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int		go_option(int option, all_t *a)
{
	if (option)
	{
		if (!save_bmp(a))
			return (0);
		ft_putstr("Success\nScreenshot created.\n");
	}
	else
	{
		mlx_hook(a->w.win, 2, 0, key_hold, a);
		mlx_hook(a->w.win, 3, 0, key_release, a);
		mlx_hook(a->w.win, 17, 0, key_close, a);
		mlx_loop_hook(a->w.mlx, key_read, a);
		mlx_loop(a->w.mlx);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	all_t		a;
	int			option;

	a.m.name = argv[1];
	cub_fault(argc, argv);
	option = (argc >= 3 && !ft_strncmp(argv[2], "--save", 6)) ? 1 : 0;
	if (!go_parsing(&a))
		ret_exit("Error\nPasring failure.\n", &a);
	if (!go_option(option, &a))
		ret_exit("Error\nOption failure.\n", &a);
	ret_exit("Exited at end\n", &a);
	return (EXIT_SUCCESS);
}
