/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:37:52 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 15:52:32 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_color(int i, int n, char *line, all_t *a)
{
	if (n < 3 && line[i] != ',')
		m_exit(24, a);
	if (n > 3 || a->m.rgb < 0 || a->m.rgb > 255)
		m_exit(25, a);
	if (n == 3 && line[i])
		m_exit(62, a);
}

int		syntax_color(char *line, all_t *a)
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (line[i])
	{
		a->m.rgb = 0;
		pass_space(&i, line);
		if (n < 3 && !ft_isdigit(line[i]))
			m_exit(13, a);
		while (ft_isdigit(line[i]))
			a->m.rgb = a->m.rgb * 10 + (line[i++] - 48);
		n++;
		pass_space(&i, line);
		check_color(i, n, line, a);
		if ((size_t)i < ft_strlen(line))
			i++;
	}
	if (n < 3)
		m_exit(62, a);
	return (1);
}

char	*map_cut(char *line, all_t *a)
{
	int		i;

	i = 1;
	if (ft_isstr(line[0], "RNSWEF"))
	{
		if (ft_isstr(line[1], "OEA"))
			i++;
		pass_space(&i, line);
		return (line + i);
	}
	else if (line[0] == 'C')
	{
		pass_space(&i, line);
		if (!syntax_color(line, a))
			m_exit(13, a);
		return (line + i);
	}
	return (NULL);
}
