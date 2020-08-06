    #include "../includes/cub3d.h"
    
int     hold_key(int key, all_t *a)
{
	fprintf(stderr, "key = %d\n", key);
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 1;
	if (key == KEY_Q)
		a->k.q = 1;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 1;
	if (key == KEY_D)
		a->k.d = 1;
	if (key == ARROW_LEFT)
		a->k.al = 1;
	if (key == ARROW_RIGHT)
		a->k.ar = 1;
    if (key == KEY_M)
        a->k.m = 1;
	if (key == KEY_ESC)
		a->k.esc = 1;
    return (0);
}

int     release_key(int key, all_t *a)
{
	if (key == KEY_Z || key == ARROW_UP)
		a->k.z = 0;
	if (key == KEY_Q)
		a->k.q = 0;
	if (key == KEY_S || key == ARROW_DOWN)
		a->k.s = 0;
	if (key == KEY_D)
		a->k.d = 0;
	if (key == ARROW_LEFT)
		a->k.al = 0;
	if (key == ARROW_RIGHT)
		a->k.ar = 0;
	if (key == KEY_M)
        a->k.m = 0;
	if (key == KEY_ESC)
		a->k.esc = 0;
    return (0);
}

int     read_key(all_t *a)
{
        if (a->k.z == 1)
        {
            if ((a->m.map_tab[(int)(a->r.posX + a->r.dirX * a->f.moveSpeed)][(int)a->r.posY]) != '1')
                a->r.posX += a->r.dirX * a->f.moveSpeed;
            if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY + a->r.dirY * a->f.moveSpeed)]) != '1')
                a->r.posY += a->r.dirY * a->f.moveSpeed;
        }
        if (a->k.s == 1)
        {
            if ((a->m.map_tab[(int)(a->r.posX - a->r.dirX * a->f.moveSpeed)][(int)a->r.posY]) != '1')
                a->r.posX -= a->r.dirX * a->f.moveSpeed;
            if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY - a->r.dirY * a->f.moveSpeed)]) != '1')
                a->r.posY -= a->r.dirY * a->f.moveSpeed;
        }
        if (a->k.d == 1)
        {
            if ((a->m.map_tab[(int)(a->r.posX + a->r.planX * a->f.moveSpeed)][(int)a->r.posY]) != '1')
                a->r.posX += a->r.planX * a->f.moveSpeed;
            if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY + a->r.planY * a->f.moveSpeed)]) != '1')
                a->r.posY += a->r.planY * a->f.moveSpeed;
        }
        if (a->k.q == 1)
        {
            if ((a->m.map_tab[(int)(a->r.posX - a->r.planX * a->f.moveSpeed)][(int)a->r.posY]) != '1')
                a->r.posX -= a->r.planX * a->f.moveSpeed;
            if ((a->m.map_tab[(int)a->r.posX][(int)(a->r.posY - a->r.planY * a->f.moveSpeed)]) != '1')
                a->r.posY -= a->r.planY * a->f.moveSpeed;
        }
        if (a->k.ar == 1)
        {
            a->f.oldDirX = a->r.dirX;
            a->r.dirX = a->r.dirX * cos(-a->f.rotSpeed) - a->r.dirY * sin(-a->f.rotSpeed);
            a->r.dirY = a->f.oldDirX * sin(-a->f.rotSpeed) + a->r.dirY * cos(-a->f.rotSpeed);
            a->f.oldPlanX = a->r.planX;
            a->r.planX = a->r.planX * cos(-a->f.rotSpeed) - a->r.planY * sin(-a->f.rotSpeed);
            a->r.planY = a->f.oldPlanX * sin(-a->f.rotSpeed) + a->r.planY * cos(-a->f.rotSpeed);
        }
        if (a->k.al == 1)
        {
            a->f.oldDirX = a->r.dirX;
            a->r.dirX = a->r.dirX * cos(a->f.rotSpeed) - a->r.dirY * sin(a->f.rotSpeed);
            a->r.dirY = a->f.oldDirX * sin(a->f.rotSpeed) + a->r.dirY * cos(a->f.rotSpeed);
            a->f.oldPlanX = a->r.planX;
            a->r.planX = a->r.planX * cos(a->f.rotSpeed) - a->r.planY * sin(a->f.rotSpeed);
            a->r.planY = a->f.oldPlanX * sin(a->f.rotSpeed) + a->r.planY * cos(a->f.rotSpeed);
        }
	    if (a->k.esc == 1)
	    	ft_close(a);
	    if (a->k.m == 1)
	    {
	    	if (a->m.map_count == 0)
	    	{
	    		a->m.map_count = 1;
	    	}
	    	else if (a->m.map_count == 1)
	    	{
	    		mlx_destroy_image(a->w.mlx, a->m.img_map_ptr);
	    		a->m.map_count = 0;
	    	}
	    }
		if (a->m.map_count == 1)
		{
			ray_launch(a);
			a->m.img_map_ptr = mlx_new_image(a->w.mlx, a->m.map_w * 20, a->m.map_h * 20);
    		a->m.img_map_data = (int *)mlx_get_data_addr(a->m.img_map_ptr, &a->m.map_bpp, &a->m.map_size_line, &a->m.map_endian);
        	map_show(a);
    		mlx_put_image_to_window(a->w.mlx, a->w.win, a->m.img_map_ptr, 0, 0);
		}
		else if (a->m.map_count == 0)
			ray_launch(a);
    return (0);
}