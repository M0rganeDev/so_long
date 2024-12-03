/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:37 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 13:44:53 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_parser.h"

static int	is_wall_or_eol(char id)
{
	return (id == '1' || id == '\n');
}

int	map_leak_to_void(t_game_data *data, t_infos *infos)
{
	t_vector2i	tmp;

	tmp.y = 0;
	infos->map_x = ft_strlen(data->map_data[tmp.y]);
	while (tmp.y < infos->map_y)
	{
		tmp.x = 0;
		if (tmp.y == 0 || tmp.y == infos->map_y - 1)
		{
			while (data->map_data[tmp.y][tmp.x])
			{
				if (!is_wall_or_eol(data->map_data[tmp.y][tmp.x]))
					return (0);
				++tmp.x;
			}
		}
		else if (!is_wall_or_eol(data->map_data[tmp.y][0])
				|| !is_wall_or_eol(data->map_data[tmp.y][infos->map_x - 1]))
			return (0);
		++tmp.y;
	}
	return (1);
}
