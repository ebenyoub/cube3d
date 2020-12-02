/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:14 by user42            #+#    #+#             */
/*   Updated: 2020/12/02 12:18:08 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tab_malloc(all_t *a)
{
	if (!(a->s.zbuffer = malloc(sizeof(double) * a->m.width)))
		m_exit(55, a);
	if (!(a->d = malloc(sizeof(pos_t) * a->s.spr_nbr)))
		m_exit(54, a);
	if (!(a->s.spr_dist = malloc(sizeof(double) * a->s.spr_nbr)))
		m_exit(56, a);
	if (!(a->s.order = malloc(sizeof(int) * a->s.spr_nbr)))
		m_exit(57, a);
}
