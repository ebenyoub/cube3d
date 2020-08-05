#include "../includes/cub3d.h"

int		ft_close(all_t *a)
{
		mlx_destroy_window(a->w.mlx, a->w.win);
		exit(1);
}

void    mlx_process(all_t *a)
{
	mlx_hook(a->w.win, 17, 0, ft_close, a);
	mlx_loop_hook(a->w.mlx, read_key, a);
	mlx_loop(a->w.mlx);
}