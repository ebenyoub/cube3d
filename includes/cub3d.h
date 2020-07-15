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
	void			*mlx_map;
	void			*win_map;
}					win_t;

typedef	struct 		map_s
{
	double			pos_x;
	double			pos_y;
	char			**map_tab;
	char			*sprite;
	char			*name;
	char			*map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				map_count;
	int				map_rgb[5];
	int				height;
	int				width;
	int				map_h;
	int				map_w;
	int				f;
	int				c;
	int				w;
}					map_t;

typedef struct		ray_s
{
	double			perpWallDist;
	double			deltaDistX;
	double			deltaDistY;
	double			sideDistX;	
	double			sideDistY;
	double			drawStart;
	double			drawEnd;
	double			planX;
	double			planY;
	double			rDirX;
	double			rDirY;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			camX;
	int				mapX;
	int				mapY;
	int 			hit;
	int				side;
	int				stepX; 
    int				stepY; 
	int				lineHeight;

}					ray_t;

typedef	struct		fps_s
{
	double			moveSpeed;
	double			rotSpeed;
}					fps_t;

typedef	struct		all_s
{
	win_t			w;
	map_t			m;
	ray_t			r;
	fps_t			f;
}					all_t;


void	map_draw(all_t *a, int i, int n, int colo);
void    map_save(char *line, all_t *a);
void    map_data(char *line, all_t *a);
void	map_black(all_t *a);
void    map_read(all_t *a);
void    map_show(all_t *a);
void    init_all(all_t *a);
void    init_win(all_t *a);
void    init_win_map(all_t *a);
void    mlx_process(all_t *a);
int    	error_display(int argc);
int     map_color(char *str);

void    ray_launch(all_t *a);
void    verline(int x, all_t *a);
