#include "../includes/cub3d.h"

void    key_vertical(all_t *a)
{
    if (a->k.z == 1)
    {
        if ((a->m.map_tab[(int)(a->r.posX + a->r.dirX\
		* a->f.moveSpeed)][(int)a->r.posY]) != '1')
            a->r.posX += a->r.dirX * a->f.moveSpeed;
        if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		+ a->r.dirY * a->f.moveSpeed)]) != '1')
            a->r.posY += a->r.dirY * a->f.moveSpeed;
    }
    if (a->k.s == 1)
    {
        if ((a->m.map_tab[(int)(a->r.posX - a->r.dirX\
		* a->f.moveSpeed)][(int)a->r.posY]) != '1')
            a->r.posX -= a->r.dirX * a->f.moveSpeed;
        if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		- a->r.dirY * a->f.moveSpeed)]) != '1')
            a->r.posY -= a->r.dirY * a->f.moveSpeed;
    }
}

void   key_horizontal(all_t *a)
{
    if (a->k.d == 1)
    {
        if ((a->m.map_tab[(int)(a->r.posX + a->r.planX\
		* a->f.moveSpeed)][(int)a->r.posY]) != '1')
            a->r.posX += a->r.planX * a->f.moveSpeed;
        if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		+ a->r.planY * a->f.moveSpeed)]) != '1')
            a->r.posY += a->r.planY * a->f.moveSpeed;
    }
    if (a->k.q == 1)
    {
        if ((a->m.map_tab[(int)(a->r.posX - a->r.planX\
		* a->f.moveSpeed)][(int)a->r.posY]) != '1')
            a->r.posX -= a->r.planX * a->f.moveSpeed;
        if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY\
		- a->r.planY * a->f.moveSpeed)]) != '1')
            a->r.posY -= a->r.planY * a->f.moveSpeed;
    }
}

void    key_rotation(all_t *a)
{
    if (a->k.ar == 1)
    {
        a->f.oldDirX = a->r.dirX;
        a->r.dirX = a->r.dirX * cos(-a->f.rotSpeed) - a->r.dirY\
							  * sin(-a->f.rotSpeed);
        a->r.dirY = a->f.oldDirX * sin(-a->f.rotSpeed) + a->r.dirY\
								 * cos(-a->f.rotSpeed);
        a->f.oldPlanX = a->r.planX;
        a->r.planX = a->r.planX * cos(-a->f.rotSpeed) - a->r.planY\
								* sin(-a->f.rotSpeed);
        a->r.planY = a->f.oldPlanX * sin(-a->f.rotSpeed) + a->r.planY\
								   * cos(-a->f.rotSpeed);
    }
    if (a->k.al == 1)
    {
        a->f.oldDirX = a->r.dirX;
        a->r.dirX = a->r.dirX * cos(a->f.rotSpeed) - a->r.dirY\
							  * sin(a->f.rotSpeed);
        a->r.dirY = a->f.oldDirX * sin(a->f.rotSpeed) + a->r.dirY\
								 * cos(a->f.rotSpeed);
        a->f.oldPlanX = a->r.planX;
        a->r.planX = a->r.planX * cos(a->f.rotSpeed) - a->r.planY\
							    * sin(a->f.rotSpeed);
        a->r.planY = a->f.oldPlanX * sin(a->f.rotSpeed) + a->r.planY\
								   * cos(a->f.rotSpeed);
    }
}

void    key_window(all_t *a)
{
	if (a->k.esc == 1)
		key_close(a);
	if (a->k.m == 1)
	{
		a->m.img_map_ptr = mlx_new_image(a->w.mlx,\
			a->m.map_w * 20, a->m.map_h * 20);
    	a->m.img_map_to_img = (int *)mlx_get_data_addr(a->m.img_map_ptr,\
			&a->m.map_bpp, &a->m.map_size_line, &a->m.map_endian);
    	map_to_img(a);
        ray_launch(a);
    	mlx_put_image_to_window(a->w.mlx, a->w.win, a->m.img_map_ptr, 0, 0);
        free(a->m.img_map_to_img);
	}
}

int     key_read(all_t *a)
{
    key_vertical(a);
    key_horizontal(a);
    key_rotation(a);
    key_window(a);
    return (0);
}