/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:38:59 by jowander          #+#    #+#             */
/*   Updated: 2024/07/02 10:36:00 by Jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_join(int fd, char *stash)
{
	char	*buffer;
	int		read_result;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	read_result = 1;
	while (!ft_strchr(stash, '\n') && read_result > 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(buffer);
			return (free(stash), NULL);
		}
		buffer[read_result] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
