#include "../includes/cub3d.h"

int		ft_close(all_t *a)
{
		mlx_destroy_window(a->w.mlx, a->w.win);
		exit(1);
}


int		keypress(int keycode, all_t *a)
{
	printf("key = %d\n", keycode);
	if (keycode == KEY_ESC)
		ft_close(a);
	if (keycode == KEY_M)
	{
		if (a->m.map_count == 0)
		{
    		map_show(a);
			a->m.map_count = 1;
		}
		else if (a->m.map_count == 1)
		{
			map_black(a);
			ray_launch(a);
			a->m.map_count = 0;
		}
	}
	read_key(keycode, a);
	map_black(a);
	ray_launch(a);
	return (1);
}

void    mlx_process(all_t *a)
{
	mlx_hook(a->w.win, 2, 0, keypress, a);
	mlx_hook(a->w.win, 17, 0, ft_close, a);
	mlx_loop(a->w.mlx);
}