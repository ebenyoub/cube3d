NAME		=	cub3d

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LFLAGS		=	
MEMFLAGS	=	-ggdb -fsanitize=address 

SRCS_DIR	=	./sources/
OBJ_DIR		=	./objects/
INC_DIR		=	./includes/

SRCS		=	cub_main.c
SRCS		+=	cub_gnl.c
SRCS		+=	cub_mlx.c
SRCS		+=	cub_error.c
SRCS		+=	cub_init.c
SRCS		+=	map_fill.c
SRCS		+=	map_color.c
SRCS		+=	map_draw.c
SRCS		+=	ray_init.c
SRCS		+=	ray_move.c

OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INC			=	$(addprefix -I,$(INC_DIR))

LIBFT		=	libft/libft.a

RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf


$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(INC_DIR)*.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME) --no-print-directory

make_libft:
	make -C libft/
	make bonus -C libft/

make_mlx:
	make -C minilibx_macos/

$(NAME): $(OBJ) $(INC_DIR) make_libft make_mlx
	$(CC) $(CFLAGS) $(OBJ) -I ./minilibx_macos/mlx.h ./minilibx_macos/libmlx.a ./libft/libft.a -framework OpenGL -framework AppKit -I ./libft/includes $(INC) -o $(NAME)
	
clean:
	$(RM_DIR) $(OBJ_DIR)
	$(MAKE) clean -C libft/
	$(MAKE) clean -C minilibx_macos/

fclean: clean
	$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM
	$(MAKE) fclean -C libft/

fclean_wolf: clean
	$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM

re:
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

bin: re clean


.SILENT: make_mlx
#.PRECIOUS:
.PHONY: all clean fclean re bin make_libft