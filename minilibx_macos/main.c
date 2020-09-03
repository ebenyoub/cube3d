/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:01:54 by lnieto            #+#    #+#             */
/*   Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "libft_cub.h"

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		y;
	int		x;
	int		color;

	x = 0;
	y = 0;
	ft_putstr("ok");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF test");
	while (y <= 15)
	{
		x = 0;
		while (x < 15)
			mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xcd);
		y++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
