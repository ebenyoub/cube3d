/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 16:51:36 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:03:12 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_cub.h"

static int		find_set(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		a;
	int		b;
	int		n;
	char	*str;

	if (s1)
	{
		i = 0;
		b = 0;
		a = ft_strlen(s1);
		while (find_set(s1[i], set) == 1)
			i++;
		while (a-- && (find_set(s1[a], set) == 1))
			b++;
		if ((b + i) <= a)
			n = b + i;
		else
			n = 0;
		a = ft_strlen(s1) - (n);
		if (!(str = malloc(sizeof(char) * (a))))
			return (NULL);
		return (str = ft_substr(s1, i, a));
	}
	return (NULL);
}
