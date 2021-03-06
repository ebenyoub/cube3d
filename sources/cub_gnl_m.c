/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_gnl_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:39:07 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/26 12:12:34 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		end_line_m(char **tmp, int len, char **line)
{
	if (len < 0)
		return (-1);
	if (len == 0)
	{
		if (!(*line = ft_strdup(*tmp)))
			return (-1);
		free(*tmp);
		return (0);
	}
	return (-1);
}

int		new_line_m(char **tmp, int len, char **line)
{
	int				i;
	char			*clean;

	i = 0;
	if (*tmp == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	while ((*tmp)[i] != '\n' && (*tmp)[i] != '\0')
		i++;
	if ((*tmp)[i] == '\n')
	{
		if (!((*line) = ft_substr((*tmp), 0, i)))
			return (-1);
		if (!(clean = ft_strdup(&(*tmp)[i + 1])))
			return (-1);
		free(*tmp);
		(*tmp) = clean;
	}
	else if (len < 1)
		return (end_line_m(tmp, len, line));
	return (1);
}

int		fill_buffer_m(int len, char *buffer, char **tmp)
{
	char			*clean;

	buffer[len] = '\0';
	if (*tmp == NULL)
	{
		if (!(*tmp = ft_strdup(buffer)))
			return (-1);
	}
	else
	{
		if (!(clean = ft_strjoin(*tmp, buffer)))
			return (-1);
		free(*tmp);
		*tmp = clean;
	}
	return (0);
}

int		get_next_line_m(int fd, char **line)
{
	int				len;
	char			buffer[BUFFER_SIZE + 1];
	static char		*tmp;

	if (!(line) || fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
		return (-1);
	while (ft_strchr_gnl(tmp) == 0)
	{
		if ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			if ((fill_buffer_m(len, buffer, &tmp)) == -1)
				return (-1);
		}
		else
			break ;
	}
	return (new_line_m(&tmp, len, line));
}
