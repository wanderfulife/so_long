/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:19:18 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 16:38:36 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map_array(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_array)
	{
		while (i < map->rows)
		{
			free(map->map_array[i]);
			i++;
		}
		free(map->map_array);
	}
}

static void	destroy_images(t_data *data)
{
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->collectible_img)
		mlx_destroy_image(data->mlx, data->collectible_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
}

void	cleanup(t_data *data)
{
	free_map_array(&data->map);
	if (data->mlx)
	{
		destroy_images(data);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
