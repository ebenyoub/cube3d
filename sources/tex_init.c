#include "../includes/cub3d.h"

void    tex_calc(int x, all_t *a)
{
    int     y;

    y = a->r.drawStart - 1;
    if (a->r.side == 1)
        a->t.texNum = a->r.rDirY < 0 ? 3 : 4;
    else
        a->t.texNum = a->r.rDirX < 0 ? 2 : 1;

    if(a->r.side == 0) 
        a->t.wallX = a->r.posY + a->r.perpWallDist * a->r.rDirY;
    else
        a->t.wallX = a->r.posX + a->r.perpWallDist * a->r.rDirX;
    a->t.wallX -= floor((a->t.wallX));

    a->t.texX = (int)(a->t.wallX * (double)a->i[a->t.texNum].texWidth);
    if(a->r.side == 0 && a->r.rDirX > 0)
        a->t.texX = a->i[a->t.texNum].texWidth - a->t.texX - 1;
    if(a->r.side == 1 && a->r.rDirY > 0)
        a->t.texX = a->i[a->t.texNum].texWidth - a->t.texX - 1;
    while (++y < a->r.drawEnd)
    {
        a->t.texY = ((y - a->m.height * 0.5 + a->r.lineHeight * 0.5) * a->i[a->t.texNum].texHeight - 1) / a->r.lineHeight;
        a->m.w = a->i[a->t.texNum].img_data[a->i[a->t.texNum].texWidth * a->t.texY + a->t.texX];
        a->i[0].img_data[x + y * a->m.width] = a->m.w;
    }
}