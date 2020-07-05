#include "../includes/cub3d.h"

void    ray_step(all_t *a)
{
    if (a->r.rDirX < 0) 
    { 
      a->r.stepX = -1; 
      a->r.sideDistX = (a->m.pos_x - a->r.mapX) * a->r.deltaDistX; 
    } 
    else 
    { 
      a->r.stepX = 1; 
      a->r.sideDistX = (a->r.mapX + 1.0 - a->m.pos_x) * a->r.deltaDistX; 
    } 
    if (a->r.rDirY < 0) 
    { 
      a->r.stepY = -1; 
      a->r.sideDistY = (a->m.pos_y - a->r.mapY) * a->r.deltaDistY; 
    } 
    else 
    { 
      a->r.stepY = 1; 
      a->r.sideDistY = (a->r.mapY + 1.0 - a->m.pos_y) * a->r.deltaDistY; 
    } 
}

void    ray_pos(int x, all_t *a)
{
    a->r.camX = 2 * x / (double)a->m.width - 1;
    a->r.rDirX = a->r.dirX + a->r.planX * a->r.camX;
    a->r.rDirY = a->r.dirY + a->r.planY * a->r.camX;
    a->r.mapX = (int)a->m.pos_x; 
    a->r.mapY = (int)a->m.pos_y; 
    // a->r.mapX = 5;
    // a->r.mapY = 3;
    // a->m.pos_x = 5.5;
    // a->m.pos_y = 3.5;
    a->r.deltaDistY = (a->r.rDirX == 0) ? 0 : ((a->r.rDirY == 0) ? 1 : fabs(1 / a->r.rDirY)); 
    a->r.deltaDistX = (a->r.rDirY == 0) ? 0 : ((a->r.rDirX == 0) ? 1 : fabs(1 / a->r.rDirX)); 
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
        if(a->m.map_tab[a->r.mapX][a->r.mapY] == '1')
          a->r.hit = 1;
    }
}

void    ray_wall(int x, all_t *a)
{
    if(a->r.side == 0)
        a->r.perpWallDist = (a->r.mapX - a->m.pos_x + (1 - a->r.stepX) / 2) / a->r.rDirX;
    else
        a->r.perpWallDist = (a->r.mapY - a->m.pos_y + (1 - a->r.stepY) / 2) / a->r.rDirY;
    a->r.lineHeight = (int)(a->m.height / a->r.perpWallDist);
    a->r.drawStart = -(a->r.lineHeight) / 2 + a->m.height / 2;
    if (a->r.drawStart < 0)
        a->r.drawStart = 0;
    a->r.drawEnd = a->r.lineHeight / 2 + a->m.height / 2;
    if (a->r.drawEnd >= a->m.height)
        a->r.drawEnd = a->m.height - 1;
    if(a->r.side == 1) 
        a->m.w = 16711935;
    else
        a->m.w = 16776960;
;
    fprintf(stderr, "sideDistX = %f\t\tsideDistY = %f\n", a->r.sideDistX, a->r.sideDistY);
    fprintf(stderr, "lineHeight = %d\t\tperpWallDist = %f\t\tstepY = %d\t\trDirX = %f\trDirY = %f\n", a->r.lineHeight, a->r.perpWallDist, a->r.stepY, a->r.rDirX, a->r.rDirY);
    fprintf(stderr, "start = %f\t\t\tend = %f\t\t\tx = %d\n\n", a->r.drawStart, a->r.drawEnd, x);
    fprintf(stderr, "mapX = %d\t\t\tmapY = %d\t\t\tx = %d\n\n", a->r.mapX, a->r.mapY, x);
}

void    ray_launch(all_t *a)
{
    int x = 0;
    while (x <= a->m.width)
    {
        a->r.hit = 0;
        fprintf(stderr, "avant\n");
        ray_pos(x, a);
        fprintf(stderr, "ap pos\n");
        ray_step(a);        
        fprintf(stderr, "ap step\n");
        ray_dda(a);
        fprintf(stderr, "ap dda\n");
        ray_wall(x, a);
        fprintf(stderr, "ap wall\n");
        verline(x, a);
        x++;
    }
}