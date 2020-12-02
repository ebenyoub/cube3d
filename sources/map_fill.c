/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:57:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 12:19:07 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_read(all_t *a)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if ((fd = open(a->m.name, O_RDONLY)) < 0)
		m_exit(3, a);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		map_scan(line, a);
		free(line);
	}
	verif_nb(a);
	if (a->m.pos_nb == 0)
		m_exit(48, a);
	a->m.map_tab = ft_split(a->m.map, '|');
	map_leak((int)a->r.posY, (int)a->r.posX, a);
	tab_malloc(a);
	close(fd);
}
