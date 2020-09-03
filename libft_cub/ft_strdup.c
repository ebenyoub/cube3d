/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyasbenyoub <elyasbenyoub@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:43:04 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/09/03 17:03:13 by elyasbenyou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_cub.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
