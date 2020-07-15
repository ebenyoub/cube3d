#include "../includes/cub3d.h"

void    verline(int x, all_t *a)
{
	int y = a->r.drawStart;
	while (y < a->r.drawEnd)
	{
		mlx_pixel_put(a->w.mlx, a->w.win, x, y, a->m.w);
		y++;
	}
}

void	map_black(all_t *a)
{
	int x = 0;
	int y = 0;
	while (y <= a->m.height)
	{
		while (x <= a->m.width)
		{
			mlx_pixel_put(a->w.mlx, a->w.win, x, y, map_color("0,0,0"));
			x++;
		}
		x = 0;
		y++;
	}
}

void	map_draw(all_t *a, int i, int n, int colo)
{
	int x = n * 20;
	int y = i * 20;
	while (y <= i * 20 + 20)
	{
		while (x <= n * 20 + 20)
		{
			mlx_pixel_put(a->w.mlx, a->w.win, x, y, colo);
			x++;
		}
		x = n * 20;
		y++;
	}
}

void    map_show(all_t *a)
{
    int i;
    int n;

    i = -1;
    n = -1;
    while (a->m.map_tab[++i])
    {
        while (a->m.map_tab[i][++n])
        {
            if (a->m.map_tab[i][n] == '1')
                map_draw(a, i, n, a->m.map_rgb[1] );
            else if (a->m.map_tab[i][n] == '0')
                map_draw(a, i, n, a->m.map_rgb[0] );
            else if (a->m.map_tab[i][n] == '2')
                map_draw(a, i, n, a->m.map_rgb[2] );
            else if (ft_isstr(a->m.map_tab[i][n], "NSWE"))
                map_draw(a, i, n, a->m.map_rgb[3] );
            else
                map_draw(a, i, n, a->m.map_rgb[4] );
        }
        n = -1;
    }
}