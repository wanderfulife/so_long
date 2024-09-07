NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIE
INCLUDES = -I/usr/include -Imlx -Iincludes -Iprintf/includes -Ignl
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
FT_PRINTF = printf/libftprintf.a

SRCS = src/main.c src/map_parser.c src/render.c src/player_movement.c src/utils.c \
       gnl/get_next_line.c gnl/get_next_line_utils.c src/map_validator.c\
       game_init/initialize_game.c game_init/setup_window.c game_init/player_setup.c

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(FT_PRINTF) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(FT_PRINTF):
	make -C printf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pie -o $(NAME) $(OBJS) $(FT_PRINTF) $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	make -C printf clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re