/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:59:04 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/31 15:59:44 by ebenyoub         ###   ########lyon.fr   */
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
	char	*tmp;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
	{
		tmp = ft_strjoin(a->m.map, line);
		free(a->m.map);
		a->m.map = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(a->m.map, "|");
		free(a->m.map);
		a->m.map = ft_strdup(tmp);
		free(tmp);
		map_save_next(&i, line, a);
		a->m.map_h = a->m.map_h + 1;
		if (i > a->m.map_w)
			a->m.map_w = i;
	}
}