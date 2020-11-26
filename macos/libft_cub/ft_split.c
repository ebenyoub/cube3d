/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:10:18 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/11/04 15:29:16 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft_cub.h"

static int		count_wd(char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			nb++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (nb);
}

static int		*word_mark(char *str, char c, int nb)
{
	int		i;
	int		a;
	int		*tab;

	i = 0;
	a = 0;
	if (!(tab = malloc(sizeof(int) * nb)))
		return (NULL);
	while (str[i] && (a < nb))
	{
		if (str[i] == c)
			while (str[i] == c)
				i++;
		if (str[i] != c)
		{
			tab[a++] = i;
			while (str[i] != c)
				i++;
		}
	}
	return (tab);
}

static char		*malloc_word(char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (!(word = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (word == NULL)
		return (NULL);
	word[i] = '\0';
	ft_memmove(word, str, i);
	return (word);
}

static char		**make_tab(char *str, char c)
{
	int		i;
	int		count;
	int		*mark;
	char	**tab;

	i = 0;
	count = count_wd(str, c);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[count] = NULL;
	if (!(mark = word_mark(str, c, count)))
		return (NULL);
	while (i < count)
	{
		if (!(tab[i] = malloc_word(&str[mark[i]], c)))
		{
			free(mark);
			ft_free_tab(&tab);
			return (NULL);
		}
		i++;
	}
	free(mark);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	*set;

	if (s)
	{
		if (!(set = malloc(sizeof(char) * 2)))
			return (NULL);
		set[0] = c;
		set[1] = '\0';
		free(set);
		return (make_tab((char *)s, c));
	}
	return (NULL);
}
