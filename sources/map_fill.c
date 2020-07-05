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
                a->m.pos_x = (double)i + 0.5;
                a->m.pos_y = (double)a->m.map_h + 0.5;
                map_dir(line[i], a);
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
    int			i;
	int			fd;
    int         ret;
	char		*line;

	i = -1;
    ret = 1;
    fd = 0;
    fprintf(stderr, "name = %s\n", a->m.name);
	fd = open("source/map2.cub", O_RDONLY);
    fprintf(stderr, "fd = %d\n", fd);
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        fprintf(stderr, "line = %s\n", line);
        fprintf(stderr, "ret = %d\n", ret);

		map_data(line, a);
        map_save(line, a);
    }
        fprintf(stderr, "R = %dx%d\n", a->m.width, a->m.height);
        fprintf(stderr, "map = %s|\n", a->m.map);
        fprintf(stderr, "h = %d\tw = %d\n", a->m.map_h, a->m.map_w);
    while (++i < a->m.map_h)
        a->m.map_tab = malloc(sizeof(char *) * a->m.map_w);
    if (!(a->m.map_tab = ft_split(a->m.map, '|')))
        fprintf(stderr, "Erreur split");
    int q = -1;
    while (a->m.map_tab[++q])
        fprintf(stderr, "%s\n", a->m.map_tab[q]);
	close(fd);
}