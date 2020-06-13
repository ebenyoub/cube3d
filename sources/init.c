#include "../includes/cub3d.h"

void    init_win(all_t *a)
{
    a->w.mlx = mlx_init();
	a->w.win = mlx_new_window(a->w.mlx, a->m.width, a->m.height, "cub3d");
}

void    init_all(all_t *a)
{
    init_win(a);
    a->m.width= 0;
    a->m.height = 0;
    a->m.map_h = 0;
    a->m.map_w = 0;
}
