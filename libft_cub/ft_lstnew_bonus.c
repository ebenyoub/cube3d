/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 19:34:49 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:34:51 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

t_list		*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
