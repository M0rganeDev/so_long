/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:46 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:01:51 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void		fill_str(char *res, char *s1, char *s2);

static char	*read_buffer(char *buffer)
{
	char	*left_over;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	left_over = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (*left_over == 0)
	{
		free(left_over);
		left_over = NULL;
	}
	buffer[i + 1] = 0;
	return (left_over);
}

static char	*feed_buffer(int fd, char *left_over, char *buffer)
{
	ssize_t	reddit;
	char	*tmp;

	reddit = 1;
	while (reddit > 0)
	{
		reddit = read(fd, buffer, BUFFER_SIZE);
		if (reddit == -1)
			return (free(left_over), NULL);
		else if (reddit == 0)
			break ;
		buffer[reddit] = 0;
		if (!left_over)
			left_over = ft_strdup("");
		tmp = ft_strjoin(left_over, buffer);
		free(left_over);
		left_over = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_over);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_over);
		free(buffer);
		left_over = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (free(left_over), left_over = NULL, NULL);
	line = feed_buffer(fd, left_over, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (free(left_over), left_over = NULL, buffer = NULL, NULL);
	left_over = read_buffer(line);
	return (line);
}
