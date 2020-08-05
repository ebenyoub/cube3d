#include "../includes/cub3d.h"

int		ft_close(all_t *a)
{
		mlx_destroy_window(a->w.mlx, a->w.win);
		exit(1);
}
