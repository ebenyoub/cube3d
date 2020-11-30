/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:37:52 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/30 23:51:51 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_color(int rgb, int i, int n, char *line)
{
	if (n < 3 && line[i] != ',')
		m_exit(24);
	if (n > 3 || rgb < 0 || rgb > 255)
		m_exit(25);
	if (n == 3 && line[i])
		m_exit(62);
}

int		syntax_color(char *line)
{
	int i;
	int n;
	int rgb;

	i = 1;
	n = 0;
	rgb = 0;
	while (line[i])
	{
		rgb = 0;
		pass_space(&i, line);
		if (n < 3 && !ft_isdigit(line[i]))
			m_exit(13);
		while (ft_isdigit(line[i]))
			rgb = rgb * 10 + (line[i++] - 48);
		n++;
		pass_space(&i, line);
		check_color(rgb, i, n, line);
		if ((size_t)i < ft_strlen(line))
			i++;
	}
	return (1);
}

char	*map_cut(char *line)
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
		if (!syntax_color(line))
			m_exit(13);
		return (line + i);
	}
	return (NULL);
}
