    #include "../includes/cub3d.h"
    
    void    read_key(int keycode, all_t *a)
    {
        if (keycode == KEY_Z)
        {
            if (!a->m.map_tab[(int)(a->r.posX + a->r.dirX * a->f.moveSpeed)][(int)a->r.posY])
                a->r.posX += a->r.dirX * a->f.moveSpeed;
            if (!a->m.map_tab[(int)a->r.posX][(int)(a->r.posY + a->r.dirY * a->f.moveSpeed)])
                a->r.posY += a->r.dirY * a->f.moveSpeed;
            }
        if (keycode == KEY_S)
        {
            if (!a->m.map_tab[(int)(a->r.posX - a->r.dirX * a->f.moveSpeed)][(int)a->r.posY])
                a->r.posX -= a->r.dirX * a->f.moveSpeed;
            if (!a->m.map_tab[(int)a->r.posX][(int)(a->r.posY - a->r.dirY * a->f.moveSpeed)])
                a->r.posY -= a->r.dirY * a->f.moveSpeed;
        }
        if (keycode == ARROW_RIGHT)
        {
            a->f.oldDirX = a->r.dirX;
            a->r.dirX = a->r.dirX * cos(-a->f.rotSpeed) - a->r.dirY * sin(-a->f.rotSpeed);
            a->r.dirY = a->f.oldDirX * sin(-a->f.rotSpeed) + a->r.dirY * cos(-a->f.rotSpeed);
            a->f.oldPlanX = a->r.planX;
            a->r.planX = a->r.planX * cos(-a->f.rotSpeed) - a->r.planY * sin(-a->f.rotSpeed);
            a->r.planY = a->f.oldPlanX * sin(-a->f.rotSpeed) + a->r.planY * cos(-a->f.rotSpeed);
        }
        if (keycode == ARROW_LEFT)
        {
            a->f.oldDirX = a->r.dirX;
            a->r.dirX = a->r.dirX * cos(a->f.rotSpeed) - a->r.dirY * sin(a->f.rotSpeed);
            a->r.dirY = a->f.oldDirX * sin(a->f.rotSpeed) + a->r.dirY * cos(a->f.rotSpeed);
            a->f.oldPlanX = a->r.planX;
            a->r.planX = a->r.planX * cos(a->f.rotSpeed) - a->r.planY * sin(a->f.rotSpeed);
            a->r.planY = a->f.oldPlanX * sin(a->f.rotSpeed) + a->r.planY * cos(a->f.rotSpeed);
        }
    }