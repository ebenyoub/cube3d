/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:17:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/31 15:41:56 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_fault(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Error\nToo few arguments, add the map : 'souces/map.cub'\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 3)
	{
		ft_putstr("Error\nToo much arguments.\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
	{
		ft_putstr("Error\nBad syntax argument, do you mean '--save'?\n");
		exit(EXIT_FAILURE);
	}
}

void	m_exit(int i)
{
	find_msg(i);
	exit(EXIT_FAILURE);
}

void	r_exit(int i, all_t *a)
{
	exit_free_tab(a);
	m_exit(i);
}

void	pass_space(int *i, char *line)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		*i = *i + 1;
}

char	*back_space(char *line)
{
	int len;
	int i;
	char *nline;

	i = 0;
	len = ft_strlen(line) - 1;
	while (line[len] == ' ' || line[len] == '\t')
	{
		line[len] = '\0';
		len--;
	}
	pass_space(&i, line);
	if (!(nline = ft_strdup(line + i)))
		m_exit(26);
	return (nline);
}