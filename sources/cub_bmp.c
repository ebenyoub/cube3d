/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <ebenyoub@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:05:05 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/10/18 14:13:00 by ebenyoub         ###   ########lyon.fr   */
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
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	write_data_next(int fd, int i, int j, all_t *a)
{
	int		pixel;
	int		rgb[3];

	pixel = a->i[0].img_data[j + i * a->m.width];
	rgb[0] = pixel % 256;
	pixel = pixel / 256;
	rgb[1] = pixel % 256;
	pixel = pixel / 256;
	rgb[2] = pixel % 256;
	write(fd, &rgb[0], 1);
	write(fd, &rgb[1], 1);
	write(fd, &rgb[2], 1);
}

void	write_data(all_t *a, int fd)
{
	int		i;
	int		j;

	i = a->m.height + 1;
	while (--i >= 0)
	{
		j = -1;
		while (++j < a->m.width)
			write_data_next(fd, i, j, a);
	}
}

int		save_bmp(all_t *a)
{
	int	fd;
	int	size;

	key_read(a);
	size = 54 + 3 * a->m.width * a->m.height;
	if ((fd = open("./screenshot.bmp", O_WRONLY | O_CREAT |\
						O_TRUNC | O_APPEND, 00755)) < 0)
		return (0);
	write_bmp_header(a, fd, size);
	write_data(a, fd);
	return (1);
}
