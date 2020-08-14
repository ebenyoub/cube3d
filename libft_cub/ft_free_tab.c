/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 21:11:21 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 18:59:42 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
