#include "../includes/cub3d.h"

void    ray_line(int x, all_t *a)
{
	int y = 0;
	while (y < a->m.height)
	{
		if (y < a->r.drawStart)
			a->i[0].img_data[x + y * a->m.width] = a->m.c;
		if (y >= a->r.drawStart && y <= a->r.drawEnd)
		{
			a->t.texY = ((y - a->m.height * 0.5 + a->r.lineHeight * 0.5)
				* a->i[a->t.texNum].texHeight - 1) / a->r.lineHeight;
        	a->m.w = a->i[a->t.texNum].img_data[a->i[a->t.texNum].texWidth
				* a->t.texY + a->t.texX];
        	a->i[0].img_data[x + y * a->m.width] = a->m.w;
		}
		if (y > a->r.drawEnd)
			a->i[0].img_data[x + y * a->m.width] = a->m.f;
		y++;
	}
}

void    map_player(all_t *a)
{
    int     b;
    int     c;

    b = 0;
    c = 0;
    while (b < 28)
    {
        c = 0;
        while (c < 28)
        {
            a->i[0].img_data[(a->t.tmp_x + c) + (a->t.tmp_y + b) * a->m.width] =
				a->i[5].img_data[c + b * a->i[5].texWidth];
            c++;
        }
        b++;
    }
}

void	map_draw_img(all_t *z, int i, int n, int color)
{
	int a = 0;
	int b = 0;
	int x = i * 20;
	int y = n * 20;

	while (b < 20)
	{
		a = 0;
		while (a < 20)
		{
			z->i[0].img_data[(x + a) + (y + b) * (z->m.width)] = color;
			a++;
		}
		b++;
	}
}

void    map_to_img(all_t *a)
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
                map_draw_img(a, x, y, map_color("125,213,42"));
			else if (a->m.map_tab[y][x] >= '2' && a->m.map_tab[y][x] <= '6')
                map_draw_img(a, x, y, map_color("139,69,19"));
			if (x == (int)a->r.posY && y == (int)a->r.posX)
            {
				a->t.tmp_x = x * 20 - 4;
				a->t.tmp_y = y * 20 - 4;
				map_player(a);
			}
        }
        x = -1;
    }
}