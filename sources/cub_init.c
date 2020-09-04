#include "../includes/cub3d.h"

void    init_win(all_t *a)
{
    a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
    a->i[0].img_ptr = mlx_new_image(a->w.mlx, a->m.width, a->m.height);
    a->i[0].img_data = (int *)mlx_get_data_addr(a->i[0].img_ptr, &a->i[0].bpp, &a->i[0].size_line, &a->i[0].endian);
}

void    init_map(all_t *a)
{
    int i;

    i = 0;
    a->m.width = 0;
    a->m.height = 0;
    a->m.map_h = 0;
    a->m.map_w = 0;
    a->m.map_tab = NULL;
    a->m.map_count = 0;
    a->m.map = ft_strdup("");
    a->m.w = map_color("52,149,255");
    a->f.moveSpeed = 0.04;
    a->f.rotSpeed = 0.08;
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
}

void    init_all(all_t *a)
{
    init_map(a);
    init_ray(a);
}
