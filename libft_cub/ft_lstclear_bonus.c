/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:38:54 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:34:11 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list **start;

	start = lst;
	if (*lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
		(*start) = NULL;
	}
}
