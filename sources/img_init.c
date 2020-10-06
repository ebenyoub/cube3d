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

int		img_make(int i, all_t *a)
{
	if (!(a->i[i].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.img[i - 1], &a->i[i].texWidth, &a->i[i].texHeight)))
		return (-1);
	a->i[i].img_data = (int *)mlx_get_data_addr
		(a->i[i].img_ptr, &a->i[i].bpp, &a->i[i].size_line, &a->i[i].endian);
	return (0);
}

int    spr_img(all_t *a)
{
	int i;

	i = 0;
	a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
	a->i[0].img_ptr = mlx_new_image(a->w.mlx, a->m.width, a->m.height);
	a->i[0].img_data = (int *)mlx_get_data_addr
		(a->i[0].img_ptr, &a->i[0].bpp, &a->i[0].size_line, &a->i[0].endian);
	while (++i < 6)
		if (img_make(i, a) == -1)
			return (-1);
	return (1);
}

int    init_win(all_t *a)
{
    if (spr_img(a) == -1)
		return (-1);
	return (0);
}