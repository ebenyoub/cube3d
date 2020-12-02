/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:59:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 13:03:34 by ebenyoub         ###   ########lyon.fr   */
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
	if (a->m.map_tab)
		tab_free(a->m.map_tab);
	if (a->m.map)
		free(a->m.map);
	if (a->s.zbuffer)
		free(a->s.zbuffer);
	if (a->s.spr_dist)
		free(a->s.spr_dist);
	if (a->s.order)
		free(a->s.order);
	if (a->d)
		free(a->d);
}
