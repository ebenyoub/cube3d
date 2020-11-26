/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:37:52 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/26 12:31:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_color(int rgb, int i, int n, char *line)
{
	if (line[i] == ' ' || line[i] == '\t')
		m_exit(46);
	if (n > 3 || rgb < 0 || rgb > 255)
		m_exit(25);
}

int		syntax_color(char *line)
{
	int i;
	int n;
	int rgb;

	i = 1;
	n = 0;
	rgb = 0;
	while (ft_isstr(line[i], "RNSWEFC"))
		i++;
	pass_space(&i, line);
	while (line[i])
	{
		rgb = 0;
		while (ft_isdigit(line[i]))
			rgb = rgb * 10 + (line[i++] - 48);
		if ((size_t)i >= ft_strlen(line))
			break ;
		n++;
		if (n < 3 && line[i] != ',')
			m_exit(24);
		i++;
		check_color(rgb, i, n, line);
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
