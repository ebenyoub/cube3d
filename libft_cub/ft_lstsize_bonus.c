/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:39:38 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:34:59 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
