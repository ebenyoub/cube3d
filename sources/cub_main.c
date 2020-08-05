#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	all_t        a;

	if (error_display(argc))
		return (EXIT_FAILURE);
	a.m.name = argv[1];
	init_all(&a);
	map_read(&a);
    init_win(&a);
	mlx_hook(a.w.win, 2, 0, hold_key, &a);
	mlx_hook(a.w.win, 3, 0, release_key, &a);
	mlx_hook(a.w.win, 17, 0, ft_close, &a);
	mlx_loop_hook(a.w.mlx, read_key, &a);
	mlx_loop(a.w.mlx);
	return (EXIT_SUCCESS);
}