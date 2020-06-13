#include "../includes/cub3d.h"

void	map_draw(all_t *a)
{
	int x = 240;
	int y = 130;
	while (y <= 140)
	{
		while (x <= 250)
		{
			mlx_pixel_put(a->w.mlx, a->w.win, x, y, a->m.f);
			x++;
		}
		x = 240;
		y++;
	}
}

int		ft_close(all_t *a)
{
		mlx_destroy_window(a->w.mlx, a->w.win);
		exit(1);
}

int		keypress(int keycode, all_t *a)
{
	if (keycode == KEY_ESC)
		ft_close(a);
	return (1);
}

void    mlx_process(all_t *a)
{
    map_draw(a);
	mlx_hook(a->w.win, 2, 0, keypress, a);
	mlx_hook(a->w.win, 17, 0, ft_close, a);
	mlx_loop(a->w.mlx);
}