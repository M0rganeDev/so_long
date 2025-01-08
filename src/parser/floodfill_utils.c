/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:20:46 by morgane           #+#    #+#             */
/*   Updated: 2025/01/08 16:24:21 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include <unistd.h>
#include "renderer.h"
#include "so_long.h"

void	tmp_render_world(t_game_data *data, t_vector2i origin)
{
	char	tmp;

	tmp = data->map_data[origin.y][origin.x];
	data->map_data[origin.y][origin.x] = 'E';
	if (1)
		render_world(data);
	data->map_data[origin.y][origin.x] = tmp;
}

void	reset_map(t_game_data *data)
{
	t_vector2i	pos;

	pos.y = -1;
	while (++pos.y < data->map_size.y)
	{
		pos.x = -1;
		while (++pos.x < data->map_size.x)
		{
			if (data->map_data[pos.y][pos.x] == 'V')
				data->map_data[pos.y][pos.x] = '0';
			if (data->map_data[pos.y][pos.x] == 'T')
				data->map_data[pos.y][pos.x] = 'C';
			if (data->map_data[pos.y][pos.x] == 'X')
				data->map_data[pos.y][pos.x] = 'F';
		}
	}
}
