/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:59:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/04 16:49:53 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	exit_free_tab(all_t *a)
{
	tab_free(a->m.map_tab);
	free(a->m.map);
	free(a->s.zbuffer);
	free(a->s.spr_dist);
	free(a->s.order);
	free(a->d);
}
