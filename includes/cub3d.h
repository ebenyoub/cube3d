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

typedef struct		win_s
{
	void			*mlx;
	void			*win;
}					win_t;

typedef	struct 		map_s
{
	char			**map_tab;
	char			**map_test;
	char			*sprite;
	char			*name;
	char			*map;
	char			*img[6];
	void			*img_map_ptr;
	int				*img_map_to_img;
	int				option;
	int				map_count;
	int				map_size_x;
	int				height;
	int				width;
	int				map_h;
	int				map_w;
	int				map_bpp;
	int				map_size_line;
	int				map_endian;
	int				save;
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

typedef	struct		flo_s
{
	float 			rayDirX0;
	float 			rayDirY0;
	float 			rayDirX1;
	float 			rayDirY1;
	int				p;
	float 			posZ;
	float 			rowDistance;
	float 			floorStepX;
	float			floorStepY;
	float			floorX;
	float			floorY;
	int				cellX;
	int				cellY;
	int				tx;
	int				ty;
	int				floorTexture;
	int				plafondTexture;

}					flo_t;

typedef	struct		fps_s
{
	double			moveSpeed;
	double			rotSpeed;
	double			oldDirX;
	double			oldPlanX;
}					fps_t;

typedef struct		tex_s
{
	double			wallX;
	double			step;
	double			texPos;
	int				texNum;
	int				texX;
	int				texY;
	int				tmp_x;
	int				tmp_y;
}					tex_t;

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

typedef	struct		spr_s
{
	double			*zbuffer;
	int				spr_nbr;
	int				*order;
	double			*spr_dist;
    double          spriteX;
    double          spriteY;
    double          invDet;
    double          transformX;
    double          transformY;
	int				vMoveScreen;
    int             spriteScreenX;
    int             spriteHeight;
    int             drawStartY;
    int             drawEndY;
    int             spriteWidth;
    int             drawStartX;
    int             drawEndX;
    int             stripe;
    int             texX;
    int             texY;
}                   spr_t;

typedef	struct		pos_s
{
    double          x;
    double          y;
}					pos_t;

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
	int				lock;
}					key_t;

typedef	struct		all_s
{
	win_t			w;
	map_t			m;
	ray_t			r;
	fps_t			f;
	tex_t			t;
	img_t			i[7];
	key_t			k;
	spr_t			s;
	pos_t			*d;
	flo_t			c;
}					all_t;

void	map_draw(all_t *a, int i, int n, int color);
void    map_read(all_t *a);
void    map_to_img(all_t *a);
void    map_plan(char c, all_t *a);
void    map_dir(char c, all_t *a);
void	map_leak(int x, int y, all_t *a);
int		map_leak_y(int x, int y, all_t *a);
int     map_color(char *str);

void    init_all(all_t *a);
int	    init_win(all_t *a);

void    ray_line(int x, all_t *a);
int	    ray_launch(all_t *a);

int	    key_read(all_t *a);
int		key_close(all_t *a);
int     key_hold(int key, all_t *a);
int     key_release(int key, all_t *a);

void    tex_wall(all_t *a);
void    tex_floor(all_t *a);
void    spr_data(all_t *a);
void    spr_pos(all_t *a);
void	spr_save(all_t *a);
void    spr_swap(all_t *a);

void	cub_fault(int argc, char **argv);
void	ft_get_color(int i, all_t *a);
void    tab_free(char **tab);
void	exit_free_tab(all_t *a);
void	tab_free(char **tab);
int     save_bmp(all_t *a);
char	*back_space(char *line);
void	pass_space(int *i, char *line);
void	r_exit(int i, all_t *a);
void	m_exit(int i);
void    find_msg(int i);
int		get_next_line_m(int fd, char **line);
void	map_data(char *line, all_t *a);
void	map_save(char *line, all_t *a);
void    scan_param(int argc, char **argv, all_t *a);