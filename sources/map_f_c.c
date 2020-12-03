/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_f_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:26:20 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/03 16:01:21 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_c(char *line, all_t *a)
{
	int i;

	i = 1;
	if (line[0] == 'C')
	{
		pass_space(&i, line);
		if (!ft_strncmp(line + i, "ressources/pokemon", 18))
			m_exit(63, a);
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			a->m.img[6] = ft_strdup("");
			a->m.c = map_color(map_cut(line, a));
		}
		else if (!ft_isdigit(line[i]) || line[i] != '-')
		{
			a->m.ctex_on = 1;
			if (!(a->m.img[6] = ft_strdup(map_cut(line, a))))
				m_exit(22, a);
		}
	}
}

void	map_f(char *line, all_t *a)
{
	int i;

	i = 1;
	if (line[0] == 'F')
	{
		pass_space(&i, line);
		if (!ft_strncmp(line + i, "ressources/pokemon", 18))
			m_exit(63, a);
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			a->m.img[5] = ft_strdup("");
			a->m.f = map_color(map_cut(line, a));
		}
		else if (!ft_isdigit(line[i]) || line[i] != '-')
		{
			a->m.ftex_on = 1;
			if (!(a->m.img[5] = ft_strdup(map_cut(line, a))))
				m_exit(22, a);
		}
	}
	map_c(line, a);
}
