/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:13:57 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 12:24:02 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map_array)
	{
		while (i < data->map.rows)
			free(data->map.map_array[i++]);
		free(data->map.map_array);
	}
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	close_window(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

int	game_loop(t_data *data)
{
	render_map(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	if (!initialize_game(&data, argv[1]))
	{
		cleanup(&data);
		return (1);
	}
	if (!setup_window(&data))
	{
		cleanup(&data);
		return (1);
	}
	load_images(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	cleanup(&data);
	return (0);
}
