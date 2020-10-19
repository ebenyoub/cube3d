/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:17:41 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/19 13:35:28 by ebenyoub         ###   ########lyon.fr   */
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

void	ret_exit(char *str, all_t *a)
{
	ft_putstr(str);
	exit_free_tab(a);
	key_close(a);
}
