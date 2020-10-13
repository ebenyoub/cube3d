/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:59:40 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/13 13:58:43 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    tab_free(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    tab = NULL;
}

void    exit_free(all_t *a)
{
    tab_free(a->m.map_tab);
    tab_free(a->m.map_test);
    tab_free(a->m.img);
    free(a->m.map);
    free(a->m.sprite);
    free(a->m.name);
}