/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:20:52 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 17:18:52 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	initialize_game(t_data *data, char *map_file)
{
	data->map.map_array = parse_map(map_file, &data->map);
	if (!data->map.map_array)
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}

	if (!check_map_is_playable(&data->map))
	{
		ft_printf("Error: Map is not playable\n");
		return (0);
	}
	return (1);
}