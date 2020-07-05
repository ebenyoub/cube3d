#include "../includes/cub3d.h"

int     atoi_nb(char *str)
{
    int i;
    int m;
    int a[3] = {0};
    int d;

    i = 0;
    m = -1;
    while (++m < 3)
    {
        while (ft_isdigit(str[i]) && str[i])
        {
            a[m] = a[m] * 10 + (str[i] - 48);
            i++;
        }
        i++;
    }
    d = (a[0] * 65536) + (a[1] * 256) + a[2];
    return (d);
}

int    map_color(char *str)
{
    int     a;
    
    a = atoi_nb(str);
    return (a);
}