#include "../includes/cub3d.h"

void    init_win(all_t *a)
{
    a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
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
    a->m.w = map_color("255,0,0");
    a->m.map_rgb[0] = map_color("0,255,0");
    a->m.map_rgb[1] = map_color("102,175,255");
    a->m.map_rgb[2] = map_color("0,0,255");
    a->m.map_rgb[3] = map_color("0,255,0");
    a->m.map_rgb[4] = map_color("0,0,0");
}

void    init_ray(all_t *a)
{
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
}

void    init_fps(all_t *a)
{
    a->f.moveSpeed = 0.03;
    a->f.rotSpeed = 0.08;
}

void    init_all(all_t *a)
{
    init_map(a);
    init_ray(a);
    init_fps(a);
}
