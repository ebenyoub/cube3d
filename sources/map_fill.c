#include "../includes/cub3d.h"

void    map_dir(char c, all_t *a)
{
    if(c == 'N')
    {
	    a->r.dirX = -1;
	    a->r.dirY = 0;
    }
    if(c == 'S')
    {
	    a->r.dirX = 1;
	    a->r.dirY = 0;
    }
    if(c == 'E')
    {
	    a->r.dirX = 0;
	    a->r.dirY = 1;
    }
    if(c == 'W')
    {
	    a->r.dirX = 0;
	    a->r.dirY = -1;
    }
}

void    map_plan(char c, all_t *a)
{
	if (c == 'N')
	{
		a->r.planX = 0;
		a->r.planY = 0.66;
	}
	if (c == 'S')
	{
		a->r.planX = 0;
		a->r.planY = -0.66;
	}
	if (c == 'W')
	{
		a->r.planX = -0.66;
		a->r.planY = 0;
	}
	if (c == 'E')
	{
		a->r.planX = 0.66;
		a->r.planY = 0;
	}
}

void    map_save(char *line, all_t *a)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == '1')
    {
        a->m.map = ft_strjoin(a->m.map, line);
        a->m.map = ft_strjoin(a->m.map, "|");
        while (ft_isdigit(line[i]) || ft_isstr(line[i], "NSEW"))
        {
            if (ft_isstr(line[i], "NSEW"))
            {
                a->r.posX = (double)a->m.map_h + 0.5;
                a->r.posY = (double)i + 0.5;
                map_dir(line[i], a);
                map_plan(line[i], a);
            }
            i++;
        }
        a->m.map_h = a->m.map_h + 1;
        if(i > a->m.map_w)
            a->m.map_w = i;
    }
}

void    map_data(char *line, all_t *a)
{
    int i;

    i = 2;
    if (line[0] == 'R')
    {
        while (ft_isdigit(line[i]))
            a->m.width = a->m.width * 10 + (line[i++] - 48);
        i++;
        while (ft_isdigit(line[i]))
            a->m.height = a->m.height * 10 + (line[i++] - 48);
    }
    if (line[0] == 'N')
        a->m.no = ft_strdup(line + 3);
    if (line[0] == 'S' && line[1] == 'O')
        a->m.so = ft_strdup(line + 3);
    if (line[0] == 'W')
        a->m.we = ft_strdup(line + 3);
    if (line[0] == 'E')
        a->m.ea = ft_strdup(line + 3);
    if (line[0] == 'S')
        a->m.sprite = ft_strdup(line + 2);
    if (line[0] == 'F')
        a->m.f = map_color(line + 2);
    if (line[0] == 'C')
        a->m.c = map_color(line + 2);
}

void    map_read(all_t *a)
{
	int			fd;
    int         ret;
	char		*line;

    ret = 1;
	fd = open(a->m.name, O_RDONLY);
    fprintf(stderr, "fd = %d\n", fd);
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
		map_data(line, a);
        map_save(line, a);
    }
    if (!(a->m.map_tab = ft_split(a->m.map, '|')))
        fprintf(stderr, "Erreur split");
    int i = -1;
    while (a->m.map_tab[++i])
        fprintf(stderr, "%d | %s\n", i, a->m.map_tab[i]);
	close(fd);
}