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
        if(a->m.map_tab[a->r.mapX][a->r.mapY] > '0')
            a->r.hit = 1;
    }
}

void    ray_wall(all_t *a)
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
        a->m.w = map_color("255,59,1");
    else
        a->m.w = map_color("52,149,255");
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
        verline(x, a);
        if (x == 0 || x == 100 || x == 200 || x == 400 || x == 500 || x == 600 || x == 640)
        {
            fprintf(stderr, "map_w[%d]\t\tsideDistX[%.2f]\t\tdeltaDistX[%.2f]\t\tlineHeight[%d]\t\tstepX[%d]\trDirX[%.2f]\tstart[%d]\tmapX[%d]\t\tposX[%.2f]\tx[%d]\n",\
                            a->m.map_w, a->r.sideDistX, a->r.deltaDistX, a->r.lineHeight, a->r.stepX, a->r.rDirX, a->r.drawStart, a->r.mapX, a->m.pos_x, x);
            fprintf(stderr, "map_h[%d]\t\tsideDistY[%.2f]\t\tdeltaDistY[%.2f]\t\tperpWallDist[%.2f]\tstepY[%d]\trDirY[%.2f]\tend[%d]\tmapY[%d]\t\tposY[%.2f]\n\n",\
                            a->m.map_h, a->r.sideDistY, a->r.deltaDistY, a->r.perpWallDist, a->r.stepY, a->r.rDirY, a->r.drawEnd, a->r.mapY, a->m.pos_y);
        }
        x++;
    }
}