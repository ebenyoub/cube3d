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
            if((a->m.w & 0x00FFFFFF) != 0)
        		a->i[0].img_data[x + y * a->m.width] = a->m.w;
			else
				a->i[0].img_data[x + y * a->m.width] = 0;
		}
		y++;
	}
}

void    map_player(all_t *a)
{
    int     b;
    int     c;

    b = 0;
    c = 0;
    while (b < a->i[6].texHeight)
    {
        c = 0;
        while (c < a->i[6].texWidth)
        {
			if ((a->i[6].img_data[c + b * a->i[6].texWidth] & 0x00FFFFFF) != 0)
            	a->i[0].img_data[(a->t.tmp_x + c) + (a->t.tmp_y + b) * a->m.width]
				= a->i[6].img_data[c + b * a->i[6].texWidth];
            c++;
        }
        b++;
    }
}

void	map_draw_img(all_t *z, int i, int n, int color)
{
	int a = 0;
	int b = 0;
	int x = i * z->m.map_size_x;
	int y = n * z->m.map_size_x;

	while (b < z->m.map_size_x)
	{
		a = 0;
		while (a < z->m.map_size_x)
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
	a->m.map_size_x = (a->m.width / 2) / a->m.map_w;
	if (a->m.map_size_x * a->m.map_h > a->m.height)
		a->m.map_size_x = a->m.height / a->m.map_h;
    while (a->m.map_tab[++y])
    {
        while (a->m.map_tab[y][++x])
        {
            if (a->m.map_tab[y][x] == '1')
                map_draw_img(a, x, y, map_color("125,213,42"));
			else if (x == (int)a->r.posY && y == (int)a->r.posX)
				map_draw_img(a, x, y, map_color("255,255,255"));
			else if (a->m.map_tab[y][x] == '2')
                map_draw_img(a, x, y, map_color("139,69,19"));
			else
                map_draw_img(a, x, y, map_color("0,0,0"));

        }
        x = -1;
    }
}