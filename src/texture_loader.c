/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:03 by morgane           #+#    #+#             */
/*   Updated: 2024/12/10 14:56:23 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "renderer.h"

static void	setup_wall_textures(t_game_data *data, t_textures *tiles)
{
	tiles->wall_full_all_sides = load_texture(data->mlx, WALL_FULL_ALL_SIDES);
	tiles->wall_empty_all_sides = load_texture(data->mlx, WALL_EMPTY_ALL_SIDES);
	tiles->wall_side_left = load_texture(data->mlx, WALL_SIDE_LEFT);
	tiles->wall_side_under = load_texture(data->mlx, WALL_SIDE_UNDER);
	tiles->wall_side_right = load_texture(data->mlx, WALL_SIDE_RIGHT);
	tiles->wall_side_over = load_texture(data->mlx, WALL_SIDE_OVER);
	tiles->wall_corner_top_right = load_texture(data->mlx,
			WALL_CORNER_TOP_RIGHT);
	tiles->wall_corner_top_left = load_texture(data->mlx, WALL_CORNER_TOP_LEFT);
	tiles->wall_corner_bottom_right = load_texture(data->mlx,
			WALL_CORNER_BOTTOM_RIGHT);
	tiles->wall_corner_bottom_left = load_texture(data->mlx,
			WALL_CORNER_BOTTOM_LEFT);
	tiles->wall_two_sides_left_right = load_texture(data->mlx,
			WALL_TWO_SIDES_LEFT_RIGHT);
	tiles->wall_two_side_top_down = load_texture(data->mlx,
			WALL_TWO_SIDE_TOP_DOWN);
	tiles->wall_empty_bottom = load_texture(data->mlx, WALL_EMPTY_BOTTOM);
	tiles->wall_empty_left = load_texture(data->mlx, WALL_EMPTY_LEFT);
	tiles->wall_empty_top = load_texture(data->mlx, WALL_EMPTY_TOP);
}

void	setup_textures(t_game_data *data)
{
	t_textures	tile;

	tile.player = load_texture(data->mlx, PLAYER_TEXTURE);
	tile.player_left = load_texture(data->mlx, PLAYER_TEXTURE_FACING_LEFT);
	tile.ground = load_texture(data->mlx, GROUND_TEXTURE);
	tile.wall_empty_right = load_texture(data->mlx, WALL_EMPTY_RIGHT);
	tile.collectible = load_texture(data->mlx, COLLECTIBLE_TEXTURE);
	tile.exit = load_texture(data->mlx, EXIT_TEXTURE);
	tile.debug = load_texture(data->mlx, DEBUG_TEXTURE);
	tile.enemy = load_texture(data->mlx, ENEMY_TEXTURE);
	setup_wall_textures(data, &tile);
	data->textures = tile;
	data->game_flags ^= GF_NEED_WORLD_REFRESH;
}
