/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: elyasbenyoub <elyasbenyoub@student.le-1    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:53:32 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2020/06/07 13:53:49 by elyasbenyou ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft_cub/libft_cub.h"
# define BUFFER_SIZE 1


int		ft_strchr_gnl(char *s);
int		get_next_line(int fd, char **line);
int		fill_buffer(int len, char *buffer, char **tmp);
int		new_line(char **tmp, int len, char **line);
int		end_line(char **tmp, int len, char **line);

#endif
