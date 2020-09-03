/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:38:08 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr       */
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
