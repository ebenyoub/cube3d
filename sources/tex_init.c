#include "../includes/cub3d.h"

void    tex_load(all_t *a)
{
    fprintf(stderr, "tex_load\n");
    if (!(a->i[1].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.so, &a->i[1].texWidth, &a->i[1].texHeight)))
        fprintf(stderr, "NULL\n");
    if (!(a->i[1].img_data = (int *)mlx_get_data_addr(a->i[1].img_ptr, &a->i[1].bpp, &a->i[1].size_line, &a->i[1].endian)))
        fprintf(stderr, "NULL2\n");
    a->i[2].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.so, &a->i[2].texWidth, &a->i[1].texHeight);
    a->i[2].img_data = (int *)mlx_get_data_addr(a->i[2].img_ptr, &a->i[2].bpp, &a->i[2].size_line, &a->i[2].endian);
    a->i[3].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.we, &a->i[3].texWidth, &a->i[3].texHeight);
    a->i[3].img_data = (int *)mlx_get_data_addr(a->i[3].img_ptr, &a->i[3].bpp, &a->i[3].size_line, &a->i[3].endian);
    a->i[4].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.ea, &a->i[4].texWidth, &a->i[4].texHeight);
    a->i[4].img_data = (int *)mlx_get_data_addr(a->i[4].img_ptr, &a->i[4].bpp, &a->i[4].size_line, &a->i[4].endian);
}

void    tex_clac(int x, all_t *a)
{
    if (a->r.side == 1)
        a->t.texNum = a->r.rDirY < 0 ? 3 : 4;
    else
        a->t.texNum = a->r.rDirX > 0 ? 2 : 1;
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
    for(int y = a->r.drawStart; y < a->r.drawEnd; y++)
    {
        a->t.texY = ((y - a->m.height * 0.5 + a->r.lineHeight * 0.5) * a->i[a->t.texNum].texHeight - 1) / a->r.lineHeight;
        a->m.w = a->i[a->t.texNum].img_data[a->i[a->t.texNum].texWidth * a->t.texY + a->t.texX];
        if(a->r.side == 1)
            a->m.w = (a->m.w >> 1) & 8355711;
        a->i[0].img_data[x + y * a->m.width] = a->m.w;
    }
}