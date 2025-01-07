/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:03 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 07:48:43 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "renderer.h"
#include "mlx.h"
#include "ft_printf.h"

static void	generate_number_tilemap(t_game_data *data, t_textures *tiles)
{
	ft_printf("Loading fonts\n");
	tiles->nbr_zero = load_texture(data->mlx, TXT_0);
	tiles->nbr_one = load_texture(data->mlx, TXT_1);
	tiles->nbr_two = load_texture(data->mlx, TXT_2);
	tiles->nbr_three = load_texture(data->mlx, TXT_3);
	tiles->nbr_four = load_texture(data->mlx, TXT_4);
	tiles->nbr_five = load_texture(data->mlx, TXT_5);
	tiles->nbr_six = load_texture(data->mlx, TXT_6);
	tiles->nbr_seven = load_texture(data->mlx, TXT_7);
	tiles->nbr_eight = load_texture(data->mlx, TXT_8);
	tiles->nbr_nine = load_texture(data->mlx, TXT_9);
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

static void	load_game_textures(t_game_data *data, t_textures *tiles)
{
	static int	scale = 32;

	tiles->player = load_texture(data->mlx, PLAYER_TEXTURE);
	tiles->player_left = load_texture(data->mlx, PLAYER_TEXTURE_FACING_LEFT);
	tiles->ground = load_texture(data->mlx, GROUND_TEXTURE);
	tiles->wall_empty_right = load_texture(data->mlx, WALL_EMPTY_RIGHT);
	tiles->collectible = load_texture(data->mlx, COLLECTIBLE_TEXTURE);
	tiles->exit = load_texture(data->mlx, EXIT_TEXTURE);
	tiles->enemy = load_texture(data->mlx, ENEMY_TEXTURE);
	ft_printf("Loading loading UI\n");
	tiles->slash = load_texture(data->mlx, SLASH_TEXTURE);
	tiles->step_label = mlx_xpm_file_to_image(data->mlx, STEP_LABEL_TEXTURE,
			&scale, &scale);
	tiles->collected = mlx_xpm_file_to_image(data->mlx, COLLECTED_TEXTURE,
			&scale, &scale);
}

int	setup_textures(t_game_data *data)
{
	t_textures	tile;

	ft_printf("Loading main textures\n");
	tile.debug = load_texture(data->mlx, DEBUG_TEXTURE);
	if (tile.debug == NULL)
	{
		ft_printf("Error : can't load texture (check PWD ?)\n");
		return (0);
	}
	setup_wall_textures(data, &tile);
	load_game_textures(data, &tile);
	generate_number_tilemap(data, &tile);
	data->textures = tile;
	data->game_flags ^= GF_NEED_WORLD_REFRESH;
	return (1);
}
