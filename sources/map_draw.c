#include "../includes/cub3d.h"

void    verline(int x, all_t *a)
{
	int y = 0;
	while (y < a->m.height)
	{
		if (y < a->r.drawStart)
			a->f.img_data[x + y * a->m.width] = a->m.c;
		if (y >= a->r.drawStart && y <= a->r.drawEnd)
			a->f.img_data[x + y * a->m.width] = a->m.w;
		if (y > a->r.drawEnd)
			a->f.img_data[x + y * a->m.width] = a->m.f;
		y++;
	}
}

void	map_draw_img(all_t *z, int i, int n, int colo)
{
	int a = 0;
	int b = 0;
	int x = i * 20;
	int y = n * 20;

	while (b < 20)
	{
		while (a < 20)
		{
			z->m.img_map_data[(x + a) + (y + b) * (z->m.map_w * 20)] = colo;
			a++;
		}
		a = 0;
		b++;
	}
}

void    map_show(all_t *a)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while (a->m.map_tab[++y])
    {
        while (a->m.map_tab[y][++x])
        {
            if (a->m.map_tab[y][x] == '1')
                map_draw_img(a, x, y, map_color("139,69,19") );
            else if (a->m.map_tab[y][x] == '0')
                map_draw_img(a, x, y, map_color("0,0,0"));
            else if (a->m.map_tab[y][x] == '2')
                map_draw_img(a, x, y, map_color("0,0,0"));
            else
                map_draw_img(a, x, y, map_color("0,0,0"));
			if (x == (int)a->r.posY && y == (int)a->r.posX)
                map_draw_img(a, x, y, map_color("255,255,255"));
        }
        x = -1;
    }
}