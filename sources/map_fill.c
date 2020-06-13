#include "../includes/cub3d.h"

void    map_save(char *line, all_t *a)
{
    int i;
    int w;

    i = 0;
    w = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == '1')
    {
        a->m.map = ft_strjoin(a->m.map, line);
        a->m.map = ft_strjoin(a->m.map, "|");
        a->m.map_h = a->m.map_h + 1;
        while (ft_isdigit(line[i]) || ft_isstr(line[i], "NSEW"))
        {
            i++;
            w++;
        }
        if(w > a->m.map_w)
            a->m.map_w = w;
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
	char		*line;

	i = 0;
	fd = open(a->m.name, O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		map_data(line, a);
        map_save(line, a);
	}
    a->m.map_tab = ft_split(a->m.map, '|');
    // fprintf(stderr, "res = %d x %d\n", a->m.width, a->m.height);
    // fprintf(stderr, "map = %d x %d\n", a->m.map_w, a->m.map_h);

    // int o = 0;
    // while (o < a->m.map_h)
    // {
    //     fprintf(stderr, "[%d]\t| %s\n", o, a->m.map_tab[o]);
    //     o++;
    // }
	close(fd);
}