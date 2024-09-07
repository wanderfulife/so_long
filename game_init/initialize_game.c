/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:20:52 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 12:21:02 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	initialize_game(t_data *data, char *map_file)
{
	data->map.map_array = parse_map(map_file, &data->map);
	if (!data->map.map_array)
	{
		printf("Error: Invalid map\n");
		return (0);
	}
	data->player.collected = 0;
	data->player.moves = 0;
	if (!find_player(data))
	{
		printf("Error: Player starting position not found\n");
		return (0);
	}
	return (1);
}
