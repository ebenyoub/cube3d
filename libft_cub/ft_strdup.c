/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:43:04 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 19:37:35 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1) + 1;
	if (!(cpy = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
