#include "../includes/cub3d.h"

#define uDiv 3
#define vDiv 3

void    spr_swap(all_t *a)
{
	int	i;
	int tmp;

	i = 0;
	while (i + 1 < a->s.spr_nbr)
	{
		if (a->s.spr_dist[a->s.order[i]] < a->s.spr_dist[a->s.order[i + 1]])
		{
			tmp = a->s.order[i];
			a->s.order[i] = a->s.order[i + 1];
			a->s.order[i + 1] = tmp;
			spr_swap(a);
		}
		i++;
	}
}

void    spr_pos(all_t *a)
{
	int i;
	int w;
	int x;

	i = -1;
	w = -1;
	i = -1;
	x = 0;
	a->s.spr_dist = malloc(sizeof(double) * a->s.spr_nbr);
	a->s.order = malloc(sizeof(int) * a->s.spr_nbr);
	while (a->m.map_tab[++i])
	{
		w = -1;
		while (a->m.map_tab[i][++w])
		{
			if (a->m.map_tab[i][w] >= '2' && a->m.map_tab[i][w] <= '6')
			{
				a->d[x].x = i + 0.5;
				a->d[x].y = w + 0.5;
				a->s.order[x] = x;
				a->s.spr_dist[x] = ((a->r.posX - a->d[x].x) * (a->r.posX - a->d[x].x) + (a->r.posY - a->d[x].y) * (a->r.posY - a->d[x].y));
				x++;
			}
		}
	}
	spr_swap(a);
}

void    spr_calc_resize(int i, all_t *a)
{
	a->s.spriteX = a->d[i].x - a->r.posX;
	a->s.spriteY = a->d[i].y - a->r.posY;
	a->s.invDet = 1.0 / (a->r.planX * a->r.dirY - a->r.dirX * a->r.planY);
	a->s.transformX = a->s.invDet * (a->r.dirY * a->s.spriteX - a->r.dirX * a->s.spriteY);
	a->s.transformY = a->s.invDet * (-(a->r.planY) * a->s.spriteX + a->r.planX * a->s.spriteY);
	a->s.vMoveScreen = -(int)(a->i[6].texWidth / a->s.transformY);
	a->s.spriteScreenX = (int)((a->m.width / 2) * (1 + a->s.transformX / a->s.transformY));
	a->s.spriteHeight = abs((int)(a->m.height / (a->s.transformY))) / vDiv;
	a->s.drawStartY = -a->s.spriteHeight / 2 + a->m.height / 2 + a->s.vMoveScreen;
	if(a->s.drawStartY < 0)
		a->s.drawStartY = 0;
	a->s.drawEndY = a->s.spriteHeight / 2 + a->m.height / 2 + a->s.vMoveScreen;
	if(a->s.drawEndY >= a->m.height)
		a->s.drawEndY = a->m.height - 1;
	a->s.spriteWidth = abs((int)(a->m.height / (a->s.transformY))) / uDiv;
	a->s.drawStartX = -a->s.spriteWidth / 2 + a->s.spriteScreenX;
	if(a->s.drawStartX < 0)
		a->s.drawStartX = 0;
	a->s.drawEndX = a->s.spriteWidth / 2 + a->s.spriteScreenX;
	if(a->s.drawEndX >= a->m.width)
		a->s.drawEndX = a->m.width - 1;
}

void	ft_get_color(int i, all_t *a)
{
	i = 0;
	if (a->s.texY > 0)
	{
		if (a->i[6].img_data[a->s.texX + a->s.texY
				* a->i[6].texWidth] != 0)
			a->m.w = a->i[6].img_data [a->s.texX + a->s.texY * a->i[6].texWidth];
		else
			a->m.w = 0xBFD195;
	}
}

void    spr_data(all_t *a)
{
	int     i;
	int     y;
	int     z;
	int     d;

	i = -1;
	while (++i < a->s.spr_nbr)
	{
		spr_pos(a);
		spr_calc_resize(a->s.order[i], a);
		z = a->s.drawStartX;                
		while (z < a->s.drawEndX)
		{
			a->s.texX =  (int)(256 * (z - (-a->s.spriteWidth / 2 +
				a->s.spriteScreenX)) * a->i[6].texWidth / a->s.spriteWidth) / 256;
			if(a->s.transformY > 0 && z > 0 && z < a->m.width && a->s.transformY < a->s.zbuffer[z])
			{
				y = a->s.drawStartY;
				while (y < a->s.drawEndY) 
				{
					d = (y - a->s.vMoveScreen) * 256 - a->m.height * 128 + a->s.spriteHeight * 128;
					a->s.texY = ((d * a->i[6].texHeight) / a->s.spriteHeight) / 256;
					ft_get_color(a->s.order[i], a);
					if ((a->m.w & 0x00FFFFFF) != 0)
						a->i[0].img_data[z + y * (a->i[0].size_line / 4)] = a->m.w;
					y++;
				}
			}
			z += 1; 
		}
	}
}