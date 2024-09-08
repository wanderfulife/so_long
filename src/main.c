/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:13:57 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 17:17:26 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static int	initialize(t_data *data, char *map_file)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		return (0);
	}
	data->map.map_array = parse_map(map_file, &data->map);
	if (!data->map.map_array)
	{
		cleanup(data);
		return (0);
	}
	if (!check_map_is_playable(&data->map))
	{
		ft_printf("Error\nMap is not playable\n");
		cleanup(data);
		return (0);
	}
	if (!load_images(data))
	{
		cleanup(data);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!initialize(&data, argv[1]))
		return (1);
	data.win = mlx_new_window(data.mlx, data.map.cols * TILE_SIZE, data.map.rows
			* TILE_SIZE, "So Long");
	if (!data.win)
	{
		ft_printf("Error\nFailed to create window\n");
		cleanup(&data);
		return (1);
	}
	setup_hooks(&data);
	mlx_loop(data.mlx);
	cleanup(&data);
	return (0);
}
