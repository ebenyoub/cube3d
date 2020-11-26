/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:17:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/26 12:10:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_fault(int argc, char **argv)
{
	if (argc < 2)
		m_exit(0);
	if (argc > 3)
		m_exit(1);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		m_exit(2);
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

	i = 0;
	len = ft_strlen(line) - 1;
	while (line[len] == ' ' || line[len] == '\t')
	{
		line[len] = '\0';
		len--;
	}
	pass_space(&i, line);
	return (line + i);
}
