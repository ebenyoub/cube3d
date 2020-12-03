/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:38:21 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 20:01:41 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
