# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <time.h>
# include "../minilibx_macos/mlx.h"
# include "../includes/get_next_line.h"
# include "../libft_cub/libft_cub.h"
# include "./keycode.h"

# define BUFFER_SIZE 1

typedef struct		img_s
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				texWidth;
	int				texHeight;
}					img_t;

typedef struct		win_s
{
	void			*mlx;
	void			*win;
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
	int				height;
	int				width;
	int				map_h;
	int				map_w;
	void			*img_map_ptr;
	int				*img_map_to_img;
	int				map_bpp;
	int				map_size_line;
	int				map_endian;
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
	int				drawStart;
	int				drawEnd;
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
	double			oldDirX;
	double			oldPlanX;
}					fps_t;


typedef struct		tex_s
{
	int				texNum;
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			texPos;

}					tex_t;

typedef struct		key_s
{
	int				z;
	int				s;
	int				q;
	int				d;
	int				m;
	int				l;
	int				al;
	int				ar;
	int				esc;
}					key_t;

typedef	struct		all_s
{
	win_t			w;
	map_t			m;
	ray_t			r;
	fps_t			f;
	key_t			k;
	tex_t			t;
	img_t			i[5];
}					all_t;


int    	cub_fault(int argc);

void	map_draw(all_t *a, int i, int n, int colo);
void    map_read(all_t *a);
void    map_to_img(all_t *a);
int     map_color(char *str);

void    init_all(all_t *a);
void    init_win(all_t *a);

void    ray_launch(all_t *a);
void    ray_line(int x, all_t *a);

int	    key_read(all_t *a);
int		key_close(all_t *a);

void    tex_load(all_t *a);
void    tex_clac(int x, all_t *a);
