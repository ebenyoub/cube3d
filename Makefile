UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	sys = linux
	os = Linux
	mlx = minilibx-linux
	MFLAGS = -lmlx_Linux -L%%%% -lXext -lX11 -lm -lbsd
	COMP = -L./libft_cub -lft_cub -L./minilibx-linux $(MFLAGS)
endif
ifeq ($(UNAME), Darwin)
	sys = macos
	os = Darwin
	mlx = minilibx_macos
	MFLAGS = -framework OpenGL -framework AppKit
 	COMP = ./$(mlx)/libmlx.a ./libft_cub/libft_cub.a $(MFLAGS)
endif

NAME		=	cub3d

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
LFLAGS		=	
MEMFLAGS	=	-ggdb -fsanitize=address 

SRCS_DIR	=	./sources/
OBJ_DIR		=	./objects/
INC_DIR		=	./includes/

SRCS		=	cub_main.c
SRCS		+=	cub_gnl.c
SRCS		+=	cub_error.c
SRCS		+=	cub_init.c
SRCS		+=	cub_free.c
SRCS		+=	cub_bmp.c
SRCS		+=	cub_msg.c
SRCS		+=	cub_malloc.c
SRCS		+=	cub_gnl_m.c
SRCS		+=	cub_param.c
SRCS		+=	key_init.c
SRCS		+=	map_fill.c
SRCS		+=	map_color.c
SRCS		+=	map_draw.c
SRCS		+=	map_dir.c
SRCS		+=	map_leak.c
SRCS		+=	map_data.c
SRCS		+=	map_save.c
SRCS		+=	map_scan.c
SRCS		+=	map_elem.c
SRCS		+=	map_count.c
SRCS		+=	ray_init.c
SRCS		+=	ray_shift.c
SRCS		+=	tex_init.c
SRCS		+=	tex_floor.c
SRCS		+=	spr_calc.c
SRCS		+=	spr_utils.c
SRCS		+=	img_init.c

OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC			=	$(addprefix -I,$(INC_DIR))

libft_cub		=	libft_cub/libft_cub.a

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

script = sh ressources/choose_os.sh

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(INC_DIR)*.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


all:
	@if [ ! -e "includes/cub3d.h" ] && [ $(os) = 'Linux' ]; then ressources/linux/linux.sh; fi
	@if [ ! -e "includes/cub3d.h" ] &&  [ $(os) = 'Darwin' ]; then ressources/macos/macos.sh; fi
	@if [ ! -e $(OBJ_DIR) ]; then mkdir -p  $(OBJ_DIR); fi
	$(MAKE) $(NAME) --no-print-directory


make_libft_cub:
	make -C libft_cub/

make_mlx:
	make -C $(mlx)/

$(NAME): $(OBJ) $(INC_DIR) make_libft_cub make_mlx
	$(CC) $(CFLAGS) $(OBJ) -I ./$(mlx)/mlx.h $(INC) $(COMP)  -o $@
	
clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C libft_cub/
	$(MAKE) clean -C $(mlx)/

fclean: clean
	$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM
	$(MAKE) fclean -C libft_cub/
	ressources/clean.sh

re:
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

git:
	make fclean
	git add .
	git commit -m "transfert"
	git push

bin: re clean


.SILENT: make_mlx
#.PRECIOUS:
.PHONY: all clean fclean re bin make_libft_cub
