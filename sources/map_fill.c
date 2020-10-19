/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:57:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/19 13:51:28 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_save_next(int *i, char *line, all_t *a)
{
	while (ft_isdigit(line[*i]) || ft_isstr(line[*i], "NSEW"))
	{
		if (ft_isstr(line[*i], "NSEW"))
		{
			a->r.posX = (double)a->m.map_h + 0.5;
			a->r.posY = (double)*i + 0.5;
			map_dir(line[*i], a);
			map_plan(line[*i], a);
		}
		if (line[*i] == '2')
			a->s.spr_nbr += 1;
		*i += 1;
	}
}

void	map_save(char *line, all_t *a)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
	{
		a->m.map = ft_strjoin(a->m.map, line);
		a->m.map = ft_strjoin(a->m.map, "|");
		map_save_next(&i, line, a);
		a->m.map_h = a->m.map_h + 1;
		if (i > a->m.map_w)
			a->m.map_w = i;
	}
}

void	map_data_next(char *line, all_t *a)
{
	if (line[0] == 'N')
		a->m.img[0] = ft_strdup(line + 3);
	if (line[0] == 'S' && line[1] == 'O')
		a->m.img[1] = ft_strdup(line + 3);
	if (line[0] == 'W')
		a->m.img[2] = ft_strdup(line + 3);
	if (line[0] == 'E')
		a->m.img[3] = ft_strdup(line + 3);
	if (line[0] == 'S' && line[1] == ' ')
		a->m.img[4] = ft_strdup(line + 2);
	if (line[0] == 'F')
		a->m.img[5] = ft_strdup(line + 2);
	if (line[0] == 'C')
		a->m.c = map_color(line + 2);
}

void	map_data(char *line, all_t *a)
{
	int i;

	i = 2;
	if (line[0] == 'R')
	{
		while (ft_isdigit(line[i]))
			a->m.width = a->m.width * 10 + (line[i++] - 48);
		while (ft_isdigit(line[++i]))
			a->m.height = a->m.height * 10 + (line[i] - 48);
		if (a->m.width > 1024)
			a->m.width = 1024;
		if (a->m.height > 640)
			a->m.height = 640;
	}
	map_data_next(line, a);
}

void	map_read(all_t *a)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if ((fd = open(a->m.name, O_RDONLY)) < 0)
	{
		ft_putstr("Error\nBad syntax argument, ");
		ft_putstr("do you mean 'souces/map.cub'?\n");
		exit(EXIT_FAILURE);
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		map_data(line, a);
		map_save(line, a);
	}
	a->m.map_tab = ft_split(a->m.map, '|');
	a->m.map_test = ft_split(a->m.map, '|');
	map_leak((int)a->r.posY, (int)a->r.posX, a);
	a->d = malloc(sizeof(pos_t) * a->s.spr_nbr);
	close(fd);
}
