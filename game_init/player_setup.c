/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:22:12 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 14:03:55 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (data->map.map_array[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
