/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:21:31 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 12:21:51 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	setup_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (0);
	}
	data->win = mlx_new_window(data->mlx, data->map.cols * TILE_SIZE,
			data->map.rows * TILE_SIZE, "So Long");
	if (!data->win)
	{
		ft_printf("Error: Failed to create window\n");
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

void	load_images(t_data *data)
{
	int	width;
	int	height;

	data->wall_img = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &width,
			&height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&width, &height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&width, &height);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx,
			"assets/collectible.xpm", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm", &width,
			&height);
}
