/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:21:31 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 16:15:49 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	setup_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error\n");
		return (0);
	}
	data->win = mlx_new_window(data->mlx, data->map.cols * TILE_SIZE,
			data->map.rows * TILE_SIZE, "So Long");
	if (!data->win)
	{
		ft_printf("Error:\n");
		return (0);
	}
	return (1);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}

static void	*load_xpm(void *mlx, char *filename)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (!img)
		ft_printf("Failed to load %s\n", filename);
	return (img);
}

int	load_images(t_data *data)
{
	data->wall_img = load_xpm(data->mlx, "assets/wall.xpm");
	data->floor_img = load_xpm(data->mlx, "assets/floor.xpm");
	data->player_img = load_xpm(data->mlx, "assets/player.xpm");
	data->collectible_img = load_xpm(data->mlx, "assets/collectible.xpm");
	data->exit_img = load_xpm(data->mlx, "assets/exit.xpm");
	if (!data->wall_img || !data->floor_img || !data->player_img
		|| !data->collectible_img || !data->exit_img)
	{
		ft_printf("Error\nFailed to load one or more images\n");
		return (0);
	}
	return (1);
}
