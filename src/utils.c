/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:00 by morgane          #+#    #+#             */
/*   Updated: 2024/12/12 08:50:30 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "utils.h"
#include <stdlib.h>

int	is_valid_id(char id)
{
	if (IS_BONUS)
	{
		if (id == 'F')
			return (1);
	}
	return (id == '1' || id == '0' || id == 'P' || id == 'C' || id == 'E'
		|| id == '\n');
}

static void	delete_walls(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.wall_full_all_sides);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_all_sides);
	mlx_destroy_image(data->mlx, data->textures.wall_side_left);
	mlx_destroy_image(data->mlx, data->textures.wall_side_under);
	mlx_destroy_image(data->mlx, data->textures.wall_side_right);
	mlx_destroy_image(data->mlx, data->textures.wall_side_over);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_top_right);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_top_left);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_bottom_right);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_bottom_left);
	mlx_destroy_image(data->mlx, data->textures.wall_two_sides_left_right);
	mlx_destroy_image(data->mlx, data->textures.wall_two_side_top_down);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_bottom);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_left);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_top);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_right);
}

int	clean_up(t_game_data *data)
{
	static int	index = -1;

	mlx_destroy_image(data->mlx, data->textures.player);
	mlx_destroy_image(data->mlx, data->textures.player_left);
	mlx_destroy_image(data->mlx, data->textures.ground);
	mlx_destroy_image(data->mlx, data->textures.collectible);
	mlx_destroy_image(data->mlx, data->textures.exit);
	mlx_destroy_image(data->mlx, data->textures.debug);
	mlx_destroy_image(data->mlx, data->textures.enemy);
	delete_walls(data);
	while (++index < (int)data->map_size.y)
		free(data->map_data[index]);
	free(data->map_data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_space(data);
	exit(0);
	return (0);
}

int	set_bit(int *base, int mask, int new_value)
{
	if (new_value)
		*base |= mask;
	else
		*base &= ~mask;
	return (*base);
}

int	is_valid_target_tile(t_vector2i pos, t_game_data *data)
{
	return (data->map_data[pos.y][pos.x] != '1' && pos.x < data->map_size.x
		&& pos.y < data->map_size.y);
}
