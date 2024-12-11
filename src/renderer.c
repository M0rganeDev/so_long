/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:04 by morgane          #+#    #+#             */
/*   Updated: 2024/12/11 08:56:24 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "renderer.h"
#include "so_long.h"
#include "utils.h"
#include <stdlib.h>

void	render_world(t_game_data *data)
{
	t_vector2i	pos;

	pos.y = -1;
	while (++pos.y < data->map_size.y)
	{
		pos.x = -1;
		while (++pos.x < data->map_size.x)
			if (data->map_data[pos.y][pos.x] != '\n')
				render_tile(data, texture_from_id(data->textures,
						data->map_data[pos.y][pos.x], data, pos),
					pos.x * TILE_SCALE,
					pos.y * TILE_SCALE);
	}
	set_bit(&data->game_flags, GF_NEED_WORLD_REFRESH, 0);
}

void	render_tile(t_game_data *data, void *texture, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, texture, x, y);
}

void	*load_texture(void *mlx, char *path)
{
	static int	scale = TILE_SCALE;

	return (mlx_xpm_file_to_image(mlx, path, &scale, &scale));
}

void	*texture_from_id(t_textures textures, char id, t_game_data *data,
			t_vector2i pos)
{
	if (id == '1')
		return (determine_best_wall_tile(data, pos.x, pos.y));
	if (id == '0')
		return (textures.ground);
	if (id == 'P')
	{
		if (data->game_flags & GF_PLAYER_M_INV_TXT)
			return (textures.player);
		return (textures.player_left);
	}
	if (id == 'C')
		return (textures.collectible);
	if (id == 'E')
		return (textures.exit);
	if (IS_BONUS && id == 'F')
		return (textures.enemy);
	return (textures.debug);
}
