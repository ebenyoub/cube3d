/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:20:33 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 15:02:10 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**  a->i[0] = IP | a->m.img[0] = NO
**  a->i[1] = NO | a->m.img[1] = SO
**  a->i[2] = SO | a->m.img[2] = WE
**  a->i[3] = WE | a->m.img[3] = EA
**  a->i[4] = EA | a->m.img[4] = SP
**  a->i[5] = SP | a->m.img[5] = FL
**	a->i[6] = FL
*/

void	clear_img(int i, all_t *a)
{
	while (i <= 0)
	{
		mlx_destroy_image(a->w.mlx, a->i[i].img_ptr);
		i--;
	}
}

int		img_make(int i, all_t *a)
{
	if (!(a->i[i].img_ptr = mlx_xpm_file_to_image(a->w.mlx,
		a->m.img[i - 1], &a->i[i].texWidth, &a->i[i].texHeight)))
	{
		clear_img(i, a);
		ft_putstr("Error\n>> ");
		ft_putstr(a->m.img[i - 1]);
		ft_putchar('\n');
		return (0);
	}
	if (!(a->i[i].img_data = (int *)mlx_get_data_addr(a->i[i].img_ptr,
		&a->i[i].bpp, &a->i[i].size_line, &a->i[i].endian)))
		return (0);
	return (1);
}

int		spr_img(all_t *a)
{
	int		i;

	i = 0;
	a->w.mlx = mlx_init();
	while (++i < 7)
		if (!img_make(i, a))
		return (0);
	return (1);
}

int		init_win(all_t *a)
{
	if (!spr_img(a))
		return (0);
	return (1);
}
