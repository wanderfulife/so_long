/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:22:12 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 17:18:59 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_player(t_data *data)
{
	for (int y = 0; y < data->map.rows; y++)
	{
		for (int x = 0; x < data->map.cols; x++)
		{
			if (data->map.map_array[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return (1);
			}
		}
	}
	ft_printf("Error: Player not found in the map\n");
	return (0);
}
