/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 18:24:50 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 19:42:27 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_cub.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	len;
	int				*area;

	len = size * count;
	if (!(area = malloc(len)))
		return (NULL);
	return (ft_memset(area, '\0', len));
}
