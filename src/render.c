/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:06:28 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 12:42:05 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_specific_tile(t_data *data, int x, int y, char tile_type)
{
	if (tile_type == '1')
		draw_tile(data, x, y, data->wall_img);
	else if (tile_type == '0')
		draw_tile(data, x, y, data->floor_img);
	else if (tile_type == 'C')
		draw_tile(data, x, y, data->collectible_img);
	else if (tile_type == 'E')
		draw_tile(data, x, y, data->exit_img);
	else if (tile_type == 'P')
	{
		draw_tile(data, x, y, data->player_img);
		data->player.x = x;
		data->player.y = y;
	}
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			draw_specific_tile(data, x, y, data->map.map_array[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}
