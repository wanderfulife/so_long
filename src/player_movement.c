/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:06:12 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 16:51:31 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_collectible(t_data *data, int new_x, int new_y)
{
	data->player.collected++;
	data->map.map_array[new_y][new_x] = '0';
	return (1);
}

int	handle_exit(t_data *data)
{
	if (data->player.collected == data->map.collectibles)
	{
		ft_printf("Congratulations! You won! Collected: %d / %d\n",
			data->player.collected, data->map.collectibles);
		exit(0);
	}
	return (0);
}

int	move_player(t_data *data, int new_x, int new_y)
{
	char	new_pos;

	new_pos = data->map.map_array[new_y][new_x];
	if (new_pos == '1')
		return (0);
	if (new_pos == 'C')
		handle_collectible(data, new_x, new_y);
	if (new_pos == 'E')
		return (handle_exit(data));
	update_player_position(data, new_x, new_y);
	return (1);
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	data->map.map_array[data->player.y][data->player.x] = '0';
	data->player.x = new_x;
	data->player.y = new_y;
	data->map.map_array[new_y][new_x] = 'P';
	ft_printf("Moves: %d\n", ++data->player.moves);
}

int	key_press(int keycode, t_data *data)
{
	int	moved;

	moved = 0;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119 || keycode == 65362)
		moved = move_player(data, data->player.x, data->player.y - 1);
	else if (keycode == 115 || keycode == 65364)
		moved = move_player(data, data->player.x, data->player.y + 1);
	else if (keycode == 97 || keycode == 65361)
		moved = move_player(data, data->player.x - 1, data->player.y);
	else if (keycode == 100 || keycode == 65363)
		moved = move_player(data, data->player.x + 1, data->player.y);
	if (moved)
		render_map(data);
	return (0);
}
