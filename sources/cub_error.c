/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:17:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 14:18:36 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_fault(int argc, char **argv, all_t *a)
{
	if (argc < 2)
		m_exit(0, a);
	if (argc > 3)
		m_exit(1, a);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		m_exit(2, a);
}

void	m_exit(int i, all_t *a)
{
	if (a->m.parse)
	{
		mlx_destroy_image(a->w.mlx, a->i[0].img_ptr);
		mlx_destroy_window(a->w.mlx, a->w.win);
		free(a->i[0].img_ptr);
		exit_free_tab(a);
	}
	find_msg(i);
	exit(EXIT_SUCCESS);
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
