/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:02:12 by morgane          #+#    #+#             */
/*   Updated: 2024/12/11 08:31:21 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include <unistd.h>
#include "renderer.h"

static void	reset_map(t_game_data *data)
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
		}
	}
}

static int			flood_fill(t_game_data *data, t_vector2i origin, int *found,
				int fla);

static int	internal_flood_fill(t_game_data *data, t_vector2i origin,
		int *found, int flag)
{
	int	tmp;

	tmp = flood_fill(data, vector_add_lit(origin, 1, 0), found, flag);
	if (tmp)
		return (1);
	tmp = flood_fill(data, vector_add_lit(origin, 0, 1), found, flag);
	if (tmp)
		return (1);
	tmp = flood_fill(data, vector_add_lit(origin, -1, 0), found, flag);
	if (tmp)
		return (1);
	tmp = flood_fill(data, vector_add_lit(origin, 0, -1), found, flag);
	if (tmp)
		return (1);
	return (0);
}

static int	flood_fill(t_game_data *data, t_vector2i origin, int *found,
		int fla)
{
	if (1)
		render_world(data);
	if (origin.x < 0 || origin.x >= data->map_size.x || origin.y < 0
		|| origin.y >= data->map_size.y)
		return (0);
	if (fla == 1 && *found == data->collectible_count)
		return (1);
	else if (fla == 0 && data->map_data[origin.y][origin.x] == 'P')
		return (1);
	if (data->map_data[origin.y][origin.x] == '1'
		|| (data->map_data[origin.y][origin.x] == 'V'
			|| data->map_data[origin.y][origin.x] == 'T')
		|| (*found >= data->collectible_count))
		return (0);
	if (data->map_data[origin.y][origin.x] == 'C')
	{
		*found += fla;
		data->map_data[origin.y][origin.x] = 'T';
	}
	else if (data->map_data[origin.y][origin.x] == '0')
		data->map_data[origin.y][origin.x] = 'V';
	return (internal_flood_fill(data, origin, found, fla));
}

static t_vector2i	figure_out_exit_pos(t_game_data *data)
{
	t_vector2i	pos;
	t_vector2i	invalid;

	invalid.x = -1;
	invalid.y = -1;
	pos.y = -1;
	while (++pos.y < data->map_size.y)
	{
		pos.x = -1;
		while (++pos.x < data->map_size.x)
			if (data->map_data[pos.y][pos.x] == 'E')
				return (pos);
	}
	return (invalid);
}

int	is_exit_available(t_game_data *data, t_infos *infos)
{
	t_vector2i	exit_pos;
	int			found_count;

	found_count = 0;
	data->map_size.x = infos->map_x;
	data->map_size.y = infos->map_y;
	exit_pos = figure_out_exit_pos(data);
	if (!flood_fill(data, exit_pos, &found_count, 0))
		return (0);
	reset_map(data);
	found_count = 0;
	flood_fill(data, exit_pos, &found_count, 1);
	if (found_count != data->collectible_count)
		return (0);
	reset_map(data);
	return (1);
}
