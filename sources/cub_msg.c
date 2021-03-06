/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:38:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/27 11:54:01 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	back_slash(int *a, char c)
{
	if (c == 'n')
		write(1, "\n", 1);
	if (c == 't')
		write(1, "\t", 1);
	if (c == '\"')
		write(1, "\"", 1);
	*a = *a + 1;
}

void	write_msg(int *a, char *line)
{
	while (line[*a])
	{
		if (line[*a] == '\\' && ft_isstr(line[*a + 1], "nt\""))
			back_slash(&*a, line[*a + 1]);
		else
			write(1, &line[*a], 1);
		*a = *a + 1;
	}
	write(1, "\n", 1);
}

void	open_msg(void)
{
	ft_putstr("Error\nBad syntax for \"messenger.txt\".\n");
	exit(EXIT_FAILURE);
}

void	find_msg(int i)
{
	int		fd;
	int		ret;
	int		nb;
	int		a;
	char	*line;

	ret = 1;
	a = 0;
	if ((fd = open("ressources/messenger.txt", O_RDONLY)) < 0)
		open_msg();
	while (ret > 0)
	{
		nb = 0;
		a = 0;
		ret = get_next_line_m(fd, &line);
		while (ft_isdigit(line[a]))
			nb = nb * 10 + (line[a++] - 48);
		a++;
		if (nb == i)
			write_msg(&a, line);
		if (line)
			free(line);
	}
	close(fd);
}
