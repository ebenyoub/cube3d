/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:38:08 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:33:54 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	while (*alst)
		alst = &(*alst)->next;
	*alst = new;
	new->next = NULL;
}
