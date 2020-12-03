/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:11:21 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:43:28 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	ft_free_tab(char ***tab)
{
	int	count;

	if (!tab)
		return ;
	count = 0;
	while ((*tab)[count])
	{
		free((*tab)[count]);
		count++;
	}
	free(*tab);
	*tab = NULL;
}
