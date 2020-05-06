#include "../includes/cub3d.h"

int		close(data_t *d)
{
		mlx_destroy_window(d->mlx, d->win);
		exit(1);
}

int		keypress(int keycode, data_t *d)
{
	if (keycode == KEY_ESC)
		close(d);
	return (1);
}

int		main(void)
{
	data_t        d;

	if ((d.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((d.win = mlx_new_window(d.mlx, 640, 480, "cub3d")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(d.win, 2, 0, keypress, &d);
	mlx_hook(d.win, 17, 0, close, &d);
	mlx_loop(d.mlx);
	return (EXIT_SUCCESS);
}