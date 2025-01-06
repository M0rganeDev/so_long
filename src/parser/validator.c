/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:02:58 by morgane          #+#    #+#             */
/*   Updated: 2025/01/06 16:23:26 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_parser.h"
#include <stdio.h>
#include "renderer.h"
#include "so_long.h"
#include "utils.h"
#include "ft_printf.h"

static int	is_uniq_tile(unsigned int mask, int *container)
{
	if ((*container & mask) != 0)
		return (0);
	*container ^= mask;
	return (1);
}

static int	mask_to_id(char id)
{
	if (id == 'P')
	{
		ft_printf("found the fucking player !\n");
		return (1 << 0);
	}
	if (id == 'E')
		return (1 << 1);
	return (0);
}

static int	line_count(t_game_data *d, t_infos *i)
{
	char	**map;
	int		size_y;
	int		size_x;

	map = d->map_data;
	d->collectible_count = 0;
	d->enemy_count = 0;
	size_y = 0;
	while (map[size_y] != NULL)
	{
		size_x = -1;
		while (map[size_y][++size_x])
		{
			if (map[size_y][size_x] == 'C')
				d->collectible_count++;
			if (map[size_y][size_x] == 'E')
				d->exit = &map[size_y][size_x];
			if (map[size_y][size_x] == 'F')
				d->enemy_count++;
		}
		++size_y;
	}
	return (i->map_y = size_y, i->map_x = ft_strlen(d->map_data[0]), size_y);
}

static int	scan_map(t_game_data *d, t_infos *i)
{
	t_vector2i	pos;

	while (++i->y < i->map_y)
	{
		pos.y = i->y;
		i->x = -1;
		if ((int)ft_strlen(d->map_data[i->y]) != i->map_x)
			return (0);
		while (d->map_data[i->y][++i->x])
		{
			pos.x = i->x;
			if (!is_valid_id(d->map_data[i->y][i->x]))
				return (0);
			if (d->map_data[i->y][i->x] == 'F')
				spawn_enemies(d, pos);
			if (d->map_data[i->y][i->x] == 'P'
				|| d->map_data[i->y][i->x] == 'E')
				if (!is_uniq_tile(mask_to_id(d->map_data[i->y][i->x]),
					&i->tmask))
					return (0);
		}
	}
	return (1);
}

int	validate_map(t_game_data *d)
{
	t_infos	i;

	line_count(d, &i);
	make_space_for_enemies(d);
	i.y = -1;
	i.tmask = 0;
	if (!scan_map(d, &i))
		return (0);
	if (!map_leak_to_void(d, &i))
		return (0);
	if ((i.tmask & 1) == 0 || (i.tmask & 2) == 0 || !is_exit_available(d, &i))
		return (0);
	d->base_collectible = d->collectible_count;
	return (*d->exit = '0', render_world(d), 1);
}
