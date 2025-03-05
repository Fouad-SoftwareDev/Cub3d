NAME = cub3d

SRCS =	src/bonus/minimap.c \
		src/bonus/minimap2.c \
		src/bonus/mouse_movement.c \
		src/free/free.c \
		src/free/free2.c \
		src/error/error.c \
		src/get_next_line/get_next_line_utils.c \
		src/get_next_line/get_next_line.c \
		src/movement/move.c \
		src/movement/rotate.c \
		src/movement/strafe.c \
		src/main.c \
		src/game_init.c \
		src/input.c \
		src/textures.c \
		src/raycasting/raycasting.c \
		src/raycasting/raycasting2.c \
		src/utils/atoi.c \
		src/utils/check_map.c \
		src/utils/ft_calloc.c \
		src/utils/ft_memcpy.c \
		src/utils/ft_memset.c \
		src/utils/ft_putstr_fd.c \
		src/utils/ft_strtrim.c \
		src/utils/get_colors.c \
		src/utils/get_textures.c \
		src/utils/main_utils.c \
		src/utils/map_tools.c \
		src/utils/map_utils.c \
		src/utils/raycasting_utils.c \
		src/utils/split.c \
		src/utils/utils.c \
		src/utils/utils2.c \
		src/validation/validation.c \
		src/validation/validation2.c \
		src/validation/validation3.c \

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
#	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)
#	$(RM) -r mlx_linux

# clone_mlx:
# 	@echo "Cloning minilibx-linux..."
# 	@if [ -d "mlx_linux" ]; then echo "Mlx already imported in the project.";\
# 		else git clone --quiet https://github.com/42Paris/minilibx-linux.git mlx_linux; fi

re:	fclean all

.PHONY:	all clean fclean re