/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:03 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 14:09:03 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "renderer.h"
#include "mlx.h"
#include "ft_printf.h"

static void	generate_number_tilemap(t_game_data *data)
{
	static int	s = 32;

	ft_printf("Loading fonts\n");
	data->textures.nbr_zero = mlx_xpm_file_to_image(data->mlx, TXT_0, &s, &s);
	data->textures.nbr_one = mlx_xpm_file_to_image(data->mlx, TXT_1, &s, &s);
	data->textures.nbr_two = mlx_xpm_file_to_image(data->mlx, TXT_2, &s, &s);
	data->textures.nbr_three = mlx_xpm_file_to_image(data->mlx, TXT_3, &s, &s);
	data->textures.nbr_four = mlx_xpm_file_to_image(data->mlx, TXT_4, &s, &s);
	data->textures.nbr_five = mlx_xpm_file_to_image(data->mlx, TXT_5, &s, &s);
	data->textures.nbr_six = mlx_xpm_file_to_image(data->mlx, TXT_6, &s, &s);
	data->textures.nbr_seven = mlx_xpm_file_to_image(data->mlx, TXT_7, &s, &s);
	data->textures.nbr_eight = mlx_xpm_file_to_image(data->mlx, TXT_8, &s, &s);
	data->textures.nbr_nine = mlx_xpm_file_to_image(data->mlx, TXT_9, &s, &s);
}

static void	setup_wall_textures(t_game_data *data, t_textures *tiles)
{
	ft_printf("Loading wall textures\n");
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
	static int	scale = 32;

	ft_printf("Loading main textures\n");
	tile.player = load_texture(data->mlx, PLAYER_TEXTURE);
	tile.player_left = load_texture(data->mlx, PLAYER_TEXTURE_FACING_LEFT);
	tile.ground = load_texture(data->mlx, GROUND_TEXTURE);
	tile.wall_empty_right = load_texture(data->mlx, WALL_EMPTY_RIGHT);
	tile.collectible = load_texture(data->mlx, COLLECTIBLE_TEXTURE);
	tile.exit = load_texture(data->mlx, EXIT_TEXTURE);
	tile.debug = load_texture(data->mlx, DEBUG_TEXTURE);
	tile.enemy = load_texture(data->mlx, ENEMY_TEXTURE);
	ft_printf("Loading loading UI\n");
	tile.slash = load_texture(data->mlx, SLASH_TEXTURE);
	tile.step_label = mlx_xpm_file_to_image(data->mlx, STEP_LABEL_TEXTURE,
			&scale, &scale);
	tile.collected = mlx_xpm_file_to_image(data->mlx, COLLECTED_TEXTURE,
			&scale, &scale);
	setup_wall_textures(data, &tile);
	data->textures = tile;
	generate_number_tilemap(data);
	data->game_flags ^= GF_NEED_WORLD_REFRESH;
}
