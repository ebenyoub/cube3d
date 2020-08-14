
NAME		=	cub3d

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
MEMFLAGS	=	-ggdb -fsanitize=address
MLXFLAGS 	=	-I ./minilibx-linux -L ./minilibx-linux -lmlx -lm -lbsd -lX11 -lXext
LIBFLAGS 	=	-I ./libft -L ./libft -lft

OBJS  		=	$(SRCS: .c = .o)
SRCS		=	cub_main.c
SRCS		+=	cub_init.c

LIBFT		=	libft/libft.a
MINILIBX  	=	minilibX


RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

all:
	$(MAKE) $(NAME) --no-print-directory

make_libft:
	make -C libft/
	make bonus -C libft/

make_mlx:
	make -C minilibx-linux/

$(NAME): make_libft make_mlx
	$(CC) $(OBJS) $(MLXFLAGS) $(LIBFLAGS) -o cub3d

clean:
	@$(RM_DIR)
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C minilibx-linux/

fclean: clean
	@$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM
	@$(MAKE) fclean -C libft/

fclean_wolf: clean
	@$(RM_DIR) $(NAME) a.out cub3d.dSYM a.out.dSYM

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

bin: re clean


.SILENT: make_mlx
#.PRECIOUS:
.PHONY: all clean fclean re bin make_libft