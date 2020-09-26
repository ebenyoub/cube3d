#include "../includes/cub3d.h"

void    init_win(all_t *a)
{
    int     o;

    o = 0;
    a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
    a->i[0].img_ptr = mlx_new_image(a->w.mlx, a->m.width, a->m.height);
    a->i[0].img_data = (int *)mlx_get_data_addr
        (a->i[0].img_ptr, &a->i[0].bpp, &a->i[0].size_line, &a->i[0].endian);
    while (++o < 5)
    {
        a->i[o].img_ptr = mlx_xpm_file_to_image
            (a->w.mlx, a->m.axe[o - 1], &a->i[o].texWidth, &a->i[o].texHeight);
        a->i[o].img_data = (int *)mlx_get_data_addr
            (a->i[o].img_ptr, &a->i[o].bpp, &a->i[o].size_line, &a->i[o].endian);
    }
    a->i[5].img_ptr = mlx_xpm_file_to_image
        (a->w.mlx, "./voltorb.xpm", &a->i[5].texWidth, &a->i[5].texHeight);
    a->i[5].img_data = (int *)mlx_get_data_addr
        (a->i[5].img_ptr, &a->i[5].bpp, &a->i[5].size_line, &a->i[5].endian);
    a->p.img_ptr = mlx_xpm_file_to_image
        (a->w.mlx, "./pokemon/mew.xpm", &a->p.spr_width, &a->p.spr_height);
    a->p.img_data = (int *)mlx_get_data_addr
        (a->p.img_ptr, &a->p.bpp, &a->p.size_line, &a->p.endian);
}

void    init_map(all_t *a)
{
    int i;

    i = 0;
    a->m.width = 0;
    a->m.height = 0;
    a->m.map_h = 0;
    a->m.map_w = 0;
    a->t.tmp_x = 0;
    a->t.tmp_y = 0;
    a->s.spr_nbr = 0;
    a->m.map_tab = NULL;
    a->m.map_count = 0;
    a->m.map = ft_strdup("");
    a->f.moveSpeed = 0.04;
    a->f.rotSpeed = 0.08;
    a->i[1].texWidth = 1024;
    a->i[2].texWidth = 512;
    a->i[3].texWidth = 512;
    a->i[4].texWidth = 512;
    a->i[5].texWidth = 28;
    a->i[1].texHeight = 1024;
    a->i[2].texHeight = 512;
    a->i[3].texHeight = 512;
    a->i[4].texHeight = 512;
    a->i[5].texHeight = 28;
    a->p.spr_width = 120;
    a->p.spr_height = 121;
}

void    init_ray(all_t *a)
{
    a->r.mapX = 0;
    a->r.mapY = 0;
    a->r.posX = 0;
	a->r.posY = 0;
	a->r.dirX = 0;
	a->r.dirY = 0;
	a->r.planX = 0;
	a->r.planY = 0;
    a->r.camX = 0;
    a->r.rDirX = 0;
    a->r.rDirY = 0;
    a->r.hit = 0;
    a->r.perpWallDist = 0;
    a->r.deltaDistX = 0;
    a->r.deltaDistY = 0;
    a->r.drawEnd = 0;
    a->r.drawStart = 0;
    a->r.side = 0;
}

void    init_key(all_t *a)
{
    a->k.z = 0;
	a->k.s = 0;
	a->k.q = 0;
	a->k.d = 0;
	a->k.m = 0;
	a->k.l = 0;
	a->k.al = 0;
	a->k.ar = 0;
	a->k.esc = 0;
    a->k.lock = 0;
}

void    init_all(all_t *a)
{
    init_map(a);
    init_ray(a);
    init_key(a);
}
