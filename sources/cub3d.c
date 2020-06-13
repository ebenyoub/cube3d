#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	all_t        a;

	if (error_display(argc))
		return (EXIT_FAILURE);
	a.m.name = argv[1];
	init_all(&a);
	map_read(&a);
	mlx_process(&a);
	return (EXIT_SUCCESS);
}