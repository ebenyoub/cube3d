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

// void	ray_err(int x, all_t *a)
// {
// 	fprintf(stderr, "sideDistX = %f\t\tsideDistY = %f\n", a->r.sideDistX, a->r.sideDistY);
//     fprintf(stderr, "lineHeight = %d\t\tperpWallDist = %f\t\tstepY = %d\t\trDirX = %f\trDirY = %f\n", a->r.lineHeight, a->r.perpWallDist, a->r.stepY, a->r.rDirX, a->r.rDirY);
//     fprintf(stderr, "start = %f\t\t\tend = %f\t\t\tx = %d\n\n", a->r.drawStart, a->r.drawEnd, x);
//     fprintf(stderr, "mapX = %d\t\t\tmapY = %d\t\t\tx = %d\n\n", a->r.mapX, a->r.mapY, x);
// }