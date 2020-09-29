#include "../includes/cub3d.h"

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

void	ft_get_color(int i, all_t *a)
{
	i = 0;
	if (a->s.texY >= 0)
	{
		if (a->i[6].img_data[a->s.texX + a->s.texY
				* a->i[6].texWidth] != 0)
			a->m.w = a->i[6].img_data [a->s.texX + a->s.texY * a->i[6].texWidth];
		else
			a->m.w = 0xBFD195;
	}
}
