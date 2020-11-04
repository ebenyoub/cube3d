/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:37:52 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/01 21:52:33 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		syntax_color(char	*line)
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
		n++;
		if (n < 3 && line[i] != ',')
			m_exit(24);
		i++;
        if (line[i] == ' ' || line[i] == '\t')
            m_exit(46);
		if (n > 3 || rgb < 0 || rgb > 255)
			m_exit(25);
	}
	return (1);
}

char	*map_cut(char *line)
{
	int		i;
	char	*str;

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
		if(!syntax_color(line))
			m_exit(13);
		if (!(str = ft_strdup(line + i)))
			m_exit(16);
		return (str);
	}
	return (NULL);
}