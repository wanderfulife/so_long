/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:06:05 by Jowander          #+#    #+#             */
/*   Updated: 2024/09/07 16:39:54 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	remove_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

static char	**read_map(int fd, t_map *map_info)
{
	char	**map;
	char	*line;
	int		row;

	map = malloc(sizeof(char *) * (MAX_ROWS + 1));
	if (!map)
		return (NULL);
	row = 0;
	line = get_next_line(fd);
	while (line && row < MAX_ROWS)
	{
		remove_newline(line);
		map[row] = ft_strdup(line);
		free(line);
		if (row == 0)
			map_info->cols = ft_strlen(map[row]);
		row++;
		line = get_next_line(fd);
	}
	map[row] = NULL;
	map_info->rows = row;
	return (map);
}

static void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	validate_and_process_map(char **map, t_map *map_info)
{
	if (!validate_map_structure(map, map_info) || !validate_map(map, map_info))
	{
		ft_printf("Error\nInvalid map structure or content\n");
		free_map(map, map_info->rows);
		return (0);
	}
	return (1);
}

char	**parse_map(char *filename, t_map *map_info)
{
	char	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to open map file\n");
		return (NULL);
	}
	map = read_map(fd, map_info);
	close(fd);
	if (!map || !validate_and_process_map(map, map_info))
		return (NULL);
	return (map);
}
