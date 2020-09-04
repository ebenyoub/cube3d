#include "../includes/cub3d.h"

void    ray_step(all_t *a)
{
    if (a->r.rDirX < 0) 
    { 
      a->r.stepX = -1; 
      a->r.sideDistX = (a->r.posX - a->r.mapX) * a->r.deltaDistX; 
    } 
    else 
    { 
      a->r.stepX = 1; 
      a->r.sideDistX = (a->r.mapX + 1.0 - a->r.posX) * a->r.deltaDistX; 
    } 
    if (a->r.rDirY < 0) 
    { 
      a->r.stepY = -1; 
      a->r.sideDistY = (a->r.posY - a->r.mapY) * a->r.deltaDistY; 
    } 
    else 
    { 
      a->r.stepY = 1; 
      a->r.sideDistY = (a->r.mapY + 1.0 - a->r.posY) * a->r.deltaDistY; 
    } 
}

void    ray_pos(int x, all_t *a)
{
    a->r.camX = 2 * x / (double)a->m.width - 1;
    a->r.rDirX = a->r.dirX + a->r.planX * a->r.camX;
    a->r.rDirY = a->r.dirY + a->r.planY * a->r.camX;
    a->r.mapX = (int)a->r.posX;
    a->r.mapY = (int)a->r.posY;
    a->r.deltaDistY = (a->r.rDirX == 0) ? 0 : ((a->r.rDirY == 0)\
                    ? 1 : fabs(1 / a->r.rDirY)); 
    a->r.deltaDistX = (a->r.rDirY == 0) ? 0 : ((a->r.rDirX == 0)\
                    ? 1 : fabs(1 / a->r.rDirX)); 
}

void    ray_dda(all_t *a)
{
    while (a->r.hit == 0)
    {
        if(a->r.sideDistX < a->r.sideDistY)
        {
          a->r.sideDistX = a->r.sideDistX + a->r.deltaDistX;
          a->r.mapX = a->r.mapX + a->r.stepX;
          a->r.side = 0;
        }
        else
        {
          a->r.sideDistY = a->r.sideDistY + a->r.deltaDistY;
          a->r.mapY = a->r.mapY + a->r.stepY;
          a->r.side = 1;
        }
        if (a->m.map_tab[a->r.mapX][a->r.mapY] == '1')
            a->r.hit = 1;
    }
}

void    ray_wall(all_t *a)
{
    if(a->r.side == 0)
        a->r.perpWallDist = (a->r.mapX - a->r.posX + (1 - a->r.stepX) / 2)
                            / a->r.rDirX;
    else
        a->r.perpWallDist = (a->r.mapY - a->r.posY + (1 - a->r.stepY) / 2)
                            / a->r.rDirY;
    a->r.lineHeight = (int)(a->m.height / a->r.perpWallDist);
    a->r.drawStart = -(a->r.lineHeight) / 2 + a->m.height / 2;
    if (a->r.drawStart < 0)
        a->r.drawStart = 0;
    a->r.drawEnd = a->r.lineHeight / 2 + a->m.height / 2;
    if (a->r.drawEnd >= a->m.height)
        a->r.drawEnd = a->m.height - 1;
}

void    ray_launch(all_t *a)
{
    int x;
    
    x = 0;
    while (x < a->m.width)
    {
        a->r.hit = 0;
        ray_pos(x, a);
        ray_step(a);
        ray_dda(a);
        ray_wall(a);
        ray_line(x, a);
        x++;
    }
    mlx_put_image_to_window(a->w.mlx, a->w.win, a->i[0].img_ptr, 0, 0);
}