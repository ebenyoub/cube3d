/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:48:30 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:34:43 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*alst;
	t_list	*new;

	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	alst = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&alst, del);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (alst);
}
