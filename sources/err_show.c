#include "../includes/cub3d.h"

int    error_display(int argc)
{
	if (argc != 2)
	{
		write(1, ":: Choose the map's path...\n", 29);
		write(1, ":: ./cub3d source/map.cub", 25);
		return (1);
	}
    return (0);
}