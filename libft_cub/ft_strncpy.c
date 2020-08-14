/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 00:28:45 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 00:36:05 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_cub.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int x;

	x = 0;
	while (src[x] && x < len)
	{
		dst[x] = src[x];
		x++;
	}
	while (x != len)
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}
