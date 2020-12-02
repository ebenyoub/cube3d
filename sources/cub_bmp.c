/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:05:05 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/12/02 02:19:00 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

void	write_bmp_header(all_t *a, int fd, int size)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	set_int_in_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	set_int_in_char(header + 18, a->m.width);
	set_int_in_char(header + 22, a->m.height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)32;
	write(fd, header, 54);
}

void	write_data(all_t *a, int fd)
{
	int			i;
	int			j;

	i = a->m.height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < a->m.width)
			write(fd, &a->i[0].img_data[i * a->m.width + j], 4);
	}
}

int		save_bmp(all_t *a)
{
	int			fd;
	int			size;

	key_read(a);
	ray_launch(a);
	size = 54 + (3 * a->m.width * a->m.height);
	if ((fd = open("./screenshot.bmp", O_WRONLY | O_CREAT |\
						O_TRUNC | O_APPEND, 00755)) < 0)
		return (0);
	write_bmp_header(a, fd, size);
	write_data(a, fd);
	close(fd);
	return (1);
}
