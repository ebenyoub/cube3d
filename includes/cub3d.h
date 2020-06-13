# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <time.h>

# include "../minilibx_macos/mlx.h"
# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "./keycode.h"

# define BUFFER_SIZE 1

typedef struct		win_s
{
	void			*mlx;
	void			*win;
}					win_t;

typedef	struct 		map_s
{
	char			*name;
	char			*map;
	char			**map_tab;
	int				map_w;
	int				map_h;
	int				width;
	int				height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	int				f;
	int				c;
}					map_t;

typedef	struct		all_s
{
	win_t			w;
	map_t			m;
}					all_t;


void    init_all(all_t *a);
void    init_win(all_t *a);
void    mlx_process(all_t *a);
int    	error_display(int argc);
void    map_read(all_t *a);
void	map_draw(all_t *a);
void    map_save(char *line, all_t *a);
void    map_data(char *line, all_t *a);
int     map_color(char *str);