/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:48:54 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 12:50:18 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_map_chars(char **map, t_map *map_info, int counts[3])
{
	int	i;
	int	j;

	i = -1;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	while (++i < map_info->rows)
	{
		j = -1;
		while (++j < map_info->cols)
		{
			if (map[i][j] == 'P')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'C')
				counts[2]++;
		}
	}
}

int	validate_map(char **map, t_map *map_info)
{
	int	i;
	int	j;
	int	counts[3];

	count_map_chars(map, map_info, counts);
	i = -1;
	while (++i < map_info->rows)
	{
		j = -1;
		while (++j < map_info->cols)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
		}
	}
	map_info->collectibles = counts[2];
	return (counts[0] == 1 && counts[1] == 1 && counts[2] > 0);
}

int	validate_map_structure(char **map, t_map *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->rows)
	{
		if (ft_strlen(map[i]) != (size_t)map_info->cols || map[i][0] != '1'
			|| map[i][map_info->cols - 1] != '1')
			return (0);
	}
	j = -1;
	while (++j < map_info->cols)
	{
		if (map[0][j] != '1' || map[map_info->rows - 1][j] != '1')
			return (0);
	}
	return (1);
}
