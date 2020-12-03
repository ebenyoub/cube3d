/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:19:32 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:36:09 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
