#include "../includes/cub3d.h"

void    tex_load(all_t *a)
{
    a->t.texWidth = 511;
    a->t.texHeight = 786;
    fprintf(stderr, "tex_load\n");
    a->i[1].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.no, &a->t.texWidth, &a->t.texHeight);
    fprintf(stderr, "size xpm = %lu\n", sizeof(a->i[1].img_ptr));
    a->i[1].img_data = (int *)mlx_get_data_addr(a->i[1].img_ptr, &a->i[1].bpp, &a->i[1].size_line, &a->i[1].endian);
    fprintf(stderr, "tex_data\n");
    a->i[2].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.so, &a->t.texWidth, &a->t.texHeight);
    a->i[2].img_data = (int *)mlx_get_data_addr(a->i[2].img_ptr, &a->i[2].bpp, &a->i[2].size_line, &a->i[2].endian);
    a->i[3].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.we, &a->t.texWidth, &a->t.texHeight);
    a->i[3].img_data = (int *)mlx_get_data_addr(a->i[3].img_ptr, &a->i[3].bpp, &a->i[3].size_line, &a->i[3].endian);
    a->i[4].img_ptr = mlx_xpm_file_to_image(a->w.mlx, a->m.no, &a->t.texWidth, &a->t.texHeight);
    a->i[4].img_data = (int *)mlx_get_data_addr(a->i[4].img_ptr, &a->i[4].bpp, &a->i[4].size_line, &a->i[4].endian);
    fprintf(stderr, "tex_end\n");
}

void    tex_clac(int x, all_t *a)
{
    a->t.texNum = a->m.map_tab[a->r.mapX][a->r.mapY];

    if(a->r.side == 0) 
        a->t.wallX = a->r.posY + a->r.perpWallDist * a->r.rDirY;
    else
        a->t.wallX = a->r.posX + a->r.perpWallDist * a->r.rDirX;
    a->t.wallX -= floor((a->t.wallX));

    a->t.texX = (int)(a->t.wallX * (double)a->t.texWidth);
    if(a->r.side == 0 && a->r.rDirX > 0)
        a->t.texX = a->t.texWidth - a->t.texX - 1;
    if(a->r.side == 1 && a->r.rDirY < 0)
        a->t.texX = a->t.texWidth - a->t.texX - 1;

    a->t.step = 1.0 * a->t.texHeight / a->r.lineHeight;
    a->t.texPos = (a->r.drawStart - a->m.height / 2 + a->r.lineHeight / 2) * a->t.step;
    for(int y = a->r.drawStart; y < a->r.drawEnd; y++)
    {
        a->t.texY = (int)a->t.texPos & (a->t.texHeight - 1);
        a->t.texPos += a->t.step;
        a->m.w = a->i[a->t.texNum].img_data[a->t.texHeight * a->t.texY + a->t.texX];
        if(a->r.side == 1)
            a->m.w = (a->m.w >> 1) & 8355711;
        a->i[0].img_data[x + y * a->m.width] = a->m.w;
    }
}