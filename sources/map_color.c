#include "../includes/cub3d.h"

int     atoi_nb(char *str)
{
    int i;
    int a[3] = {0};
    int d;

    i = 0;
    while (ft_isdigit(str[i]) && str[i])
    {
        a[0] = a[0] * 10 + (str[i] - 48);
        i++;
    }
    i++;
    while (ft_isdigit(str[i]) && str[i])
    {
        a[1] = a[1] * 10 + (str[i] - 48);
        i++;
    }
    i++;
    while (ft_isdigit(str[i]) && str[i])
    {
        a[2] = a[2] * 10 + (str[i] - 48);
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