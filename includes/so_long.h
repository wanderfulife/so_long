/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:05:30 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 17:17:10 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include "../printf/includes/ft_printf.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_ROWS 100
# define MAX_COLS 100
# define TILE_SIZE 32

typedef struct s_map
{
	int			rows;
	int			cols;
	int			collectibles;
	char		**map_array;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			collected;
	int			moves;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*wall_img;
	void		*floor_img;
	void		*player_img;
	void		*collectible_img;
	void		*exit_img;
	t_map		map;
	t_player	player;
}				t_data;

// Function prototypes
char			**parse_map(char *filename, t_map *map);
int				validate_map(char **map, t_map *map_info);
int				validate_map_structure(char **map, t_map *map_info);
int				render_map(t_data *data);
int				move_player(t_data *data, int new_x, int new_y);
int				handle_collectible(t_data *data, int new_x, int new_y);
int				handle_exit(t_data *data);
void			update_player_position(t_data *data, int new_x, int new_y);
int				key_press(int keycode, t_data *data);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t len);
int				close_window(t_data *data);
void			cleanup(t_data *data);
int				check_map_is_playable(t_map *map);

// New function prototypes for game_init
int				initialize_game(t_data *data, char *map_file);
int				game_loop(t_data *data);
int				setup_window(t_data *data);
void			setup_hooks(t_data *data);
int				find_player(t_data *data);
int				load_images(t_data *data);

#endif