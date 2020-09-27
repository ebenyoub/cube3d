#include "../includes/cub3d.h"

/*  a->i[0] = image principale  */
/*  a->i[1] = NO                */
/*  a->i[2] = SO                */
/*  a->i[3] = WE                */
/*  a->i[4] = EA                */
/*  a->i[5] = localisation		*/
/*  a->i[6] = SP                */

void    tex_img(all_t *a)
{
    a->i[1].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.axe[0], &a->i[1].texWidth, &a->i[1].texHeight);
	a->i[1].img_data = (int *)mlx_get_data_addr
		(a->i[1].img_ptr, &a->i[1].bpp, &a->i[1].size_line, &a->i[1].endian);
	a->i[2].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.axe[1], &a->i[2].texWidth, &a->i[2].texHeight);
	a->i[2].img_data = (int *)mlx_get_data_addr
		(a->i[2].img_ptr, &a->i[2].bpp, &a->i[2].size_line, &a->i[2].endian);
	a->i[3].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.axe[2], &a->i[3].texWidth, &a->i[3].texHeight);
	a->i[3].img_data = (int *)mlx_get_data_addr
		(a->i[3].img_ptr, &a->i[3].bpp, &a->i[3].size_line, &a->i[3].endian);
	a->i[4].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.axe[3], &a->i[4].texWidth, &a->i[4].texHeight);
	a->i[4].img_data = (int *)mlx_get_data_addr
		(a->i[4].img_ptr, &a->i[4].bpp, &a->i[4].size_line, &a->i[4].endian);
}

void    spr_img(all_t *a)
{
	a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
	a->i[0].img_ptr = mlx_new_image(a->w.mlx, a->m.width, a->m.height);
	a->i[0].img_data = (int *)mlx_get_data_addr
		(a->i[0].img_ptr, &a->i[0].bpp, &a->i[0].size_line, &a->i[0].endian);
	a->i[5].img_ptr = mlx_xpm_file_to_image(a->w.mlx, "./pokemon/localisation.xpm",
		&a->i[5].texWidth, &a->i[5].texHeight);
	a->i[5].img_data = (int *)mlx_get_data_addr
		(a->i[5].img_ptr, &a->i[5].bpp, &a->i[5].size_line, &a->i[5].endian);
	a->i[6].img_ptr = mlx_xpm_file_to_image
		(a->w.mlx, a->m.sprite, &a->i[6].texWidth, &a->i[6].texHeight);
	a->i[6].img_data = (int *)mlx_get_data_addr
		(a->i[6].img_ptr, &a->i[6].bpp, &a->i[6].size_line, &a->i[6].endian);
}

void    init_win(all_t *a)
{
    spr_img(a);
    tex_img(a);
}