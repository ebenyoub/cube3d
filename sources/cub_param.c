/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:41:46 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/01 11:03:27 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    scan_param(int argc, char **argv, all_t *a)
{
	if (argc < 2)
	{
		printf("\r");
		m_exit(0);
	}
	if (argc > 3)
		m_exit(1);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
			m_exit(2);
	}
	if (ft_strcmp(argv[1], "sources/map.cub"))
		m_exit(3);
	a->m.option = (argc >= 3 && !ft_strcmp(argv[2], "--save")) ? 1 : 0;
}
