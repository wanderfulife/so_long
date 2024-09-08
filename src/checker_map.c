/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:44:28 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 17:21:35 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **map, int x, int y, int *collectibles_found,
		int *exit_found)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		(*collectibles_found)++;
	else if (map[y][x] == 'E')
		*exit_found = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, collectibles_found, exit_found);
	flood_fill(map, x - 1, y, collectibles_found, exit_found);
	flood_fill(map, x, y + 1, collectibles_found, exit_found);
	flood_fill(map, x, y - 1, collectibles_found, exit_found);
}

static char	**copy_map(t_map *map)
{
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * (map->rows + 1));
	if (!temp_map)
		return (NULL);
	for (int i = 0; i < map->rows; i++)
	{
		temp_map[i] = ft_strdup(map->map_array[i]);
		if (!temp_map[i])
		{
			for (int j = 0; j < i; j++)
				free(temp_map[j]);
			free(temp_map);
			return (NULL);
		}
	}
	temp_map[map->rows] = NULL;
	return (temp_map);
}

static void	free_temp_map(char **temp_map, int rows)
{
	for (int i = 0; i < rows; i++)
		free(temp_map[i]);
	free(temp_map);
}
int	check_map_is_playable(t_map *map)
{
	char	**temp_map;
	int		player_x;
	int		player_y;
	int		collectibles_found;
	int		exit_found;
	int		is_playable;

	player_x = -1;
	player_y = -1;
	temp_map = copy_map(map);
	if (!temp_map)
	{
		ft_printf("Error: Failed to copy map\n");
		return (0);
	}
	player_x = -1, player_y = -1;
	collectibles_found = 0;
	exit_found = 0;
	for (int y = 0; y < map->rows; y++)
	{
		for (int x = 0; x < map->cols; x++)
		{
			if (map->map_array[y][x] == 'P')
			{
				player_x = x;
				player_y = y;
				break ;
			}
		}
		if (player_x != -1)
			break ;
	}
	if (player_x == -1 || player_y == -1)
	{
		ft_printf("Error: Player not found in the map\n");
		free_temp_map(temp_map, map->rows);
		return (0);
	}
	flood_fill(temp_map, player_x, player_y, &collectibles_found, &exit_found);
	is_playable = (collectibles_found == map->collectibles && exit_found);
	free_temp_map(temp_map, map->rows);
	return (is_playable);
}
