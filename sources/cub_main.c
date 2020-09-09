#include "../includes/cub3d.h"

int     key_hold(int key, all_t *a)
{
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 1;
	if (key == KEY_Q)
		a->k.q = 1;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 1;
	if (key == KEY_D)
		a->k.d = 1;
	if (key == ARROW_LEFT)
		a->k.al = 1;
	if (key == ARROW_RIGHT)
		a->k.ar = 1;
    if (key == KEY_M)
        a->k.m = 1;
	if (key == KEY_L)
        a->k.m = 1;
	if (key == KEY_ESC)
		a->k.esc = 1;
    return (0);
}

int     key_release(int key, all_t *a)
{
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 0;
	if (key == KEY_Q)
		a->k.q = 0;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 0;
	if (key == KEY_D)
		a->k.d = 0;
	if (key == ARROW_LEFT)
		a->k.al = 0;
	if (key == ARROW_RIGHT)
		a->k.ar = 0;
	if (key == KEY_M)
        a->k.m = 0;
    if (key == KEY_L)
        a->k.m = 0;
	if (key == KEY_ESC)
		a->k.esc = 0;
    return (0);
}

int		key_close(all_t *a)
{
		mlx_destroy_window(a->w.mlx, a->w.win);
		exit(1);
}

int		main(int argc, char **argv)
{
	all_t        a;

	if (cub_fault(argc))
		return (EXIT_FAILURE);
	a.m.name = argv[1];
	init_all(&a);
	map_read(&a);
    init_win(&a);
	mlx_hook(a.w.win, 2, 0, key_hold, &a);
	mlx_hook(a.w.win, 3, 0, key_release, &a);
	mlx_hook(a.w.win, 17, 0, key_close, &a);
	mlx_loop_hook(a.w.mlx, ray_launch, &a);
	mlx_loop(a.w.mlx);
	return (EXIT_SUCCESS);
}