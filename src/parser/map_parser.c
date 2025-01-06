/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:02:31 by morgane          #+#    #+#             */
/*   Updated: 2025/01/06 14:12:05 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "map_parser.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strend(const char *target, const char *end)
{
	size_t	end_size;
	size_t	target_size;

	end_size = ft_strlen(end);
	target_size = ft_strlen(target);
	if (target_size < end_size)
		return (0);
	while (end_size != 0)
	{
		if (target[target_size] != end[end_size])
			return (0);
		--end_size;
		--target_size;
	}
	return (1);
}

static int	check(int fd)
{
	return (fd > 0 && read(fd, 0, 0) >= 0);
}

int	get_line_count(int fd)
{
	int		lines;
	char	*tmp;

	if (!check(fd))
		return (-1);
	tmp = get_next_line(fd);
	lines = 0;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		++lines;
	}
	close(fd);
	return (lines);
}

// read file at *path, and return a NULL-terminated **char
char	**read_map(char *path)
{
	char	**map_data;
	char	*cline;
	int		fd;
	int		lines;
	int		tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = get_line_count(fd);
	if (lines == -1)
		return (NULL);
	map_data = (char **)ft_calloc(sizeof(char **), (lines + 1));
	fd = open(path, O_RDONLY);
	cline = get_next_line(fd);
	tmp = 0;
	while (tmp < lines)
	{
		map_data[tmp] = cline;
		cline = get_next_line(fd);
		map_data[tmp][ft_strlen(map_data[tmp]) - 1] = '\0';
		++tmp;
	}
	return (close(fd), map_data[lines] = NULL, map_data);
}
