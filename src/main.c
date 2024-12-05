/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:58:59 by morgane          #+#    #+#             */
/*   Updated: 2024/12/05 08:14:57 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "parser/map_parser.h"
#include "player.h"
#include "renderer.h"
#include "so_long.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int	loop(t_game_data *data)
{
	if ((data->game_flags & GF_NEED_WORLD_REFRESH) != 0)
		render_world(data);
	if ((data->game_flags & GF_GAME_OBJECTIVE_WON) != 0)
		clean_up(data);
	return (0);
}

int	manage_inputs(int keycode, t_game_data *data)
{
	static int	player_step = 0;

	if (keycode == ESC)
		clean_up(data);
	data->can_step = 1;
	if (keycode == UP_W || keycode == UP_W_A || keycode == UP_S
		|| keycode == UP_S_A || keycode == UP_A || keycode == UP_A_A
		|| keycode == UP_D || keycode == UP_D_A)
	{
		handle_player_inputs(keycode, data);
		if (data->game_flags & GF_PLAYER_IS_MOVING)
		{
			update_player_pos(data);
			ft_printf("Player has taken %d steps.\n", ++player_step);
		}
	}
	else
		ft_printf("key pressed: %d\n\n", keycode);
	return (0);
}

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

static void	setup_textures(t_game_data *data)
{
	t_textures	tile;

	tile.player = load_texture(data->mlx, PLAYER_TEXTURE);
	tile.player_left = load_texture(data->mlx, PLAYER_TEXTURE_FACING_LEFT);
	tile.ground = load_texture(data->mlx, GROUND_TEXTURE);
	tile.wall_empty_right = load_texture(data->mlx, WALL_EMPTY_RIGHT);
	tile.collectible = load_texture(data->mlx, COLLECTIBLE_TEXTURE);
	tile.exit = load_texture(data->mlx, EXIT_TEXTURE);
	tile.debug = load_texture(data->mlx, DEBUG_TEXTURE);
	setup_wall_textures(data, &tile);
	data->textures = tile;
	data->game_flags ^= GF_NEED_WORLD_REFRESH;
}

int	main(int argc, char **argv)
{
	t_game_data	g_data;
	int			is_valid;

	if (argc == 1 || !ft_strend(argv[1], ".ber"))
		return (0);
	g_data.game_flags = 0;
	g_data.mlx = mlx_init();
	g_data.mlx_win = mlx_new_window(g_data.mlx, 1280, 720, "Hello world!");
	setup_textures(&g_data);
	g_data.map_data = read_map(argv[1]);
	if (g_data.map_data == NULL)
		return (ft_printf("Error\n") - ft_strlen("Error\n"));
	is_valid = validate_map(&g_data);
	figure_out_player_pos(&g_data);
	if (!is_valid)
		return (ft_printf("Error\n") - ft_strlen("Error\n"));
	*g_data.exit = '0';
	mlx_key_hook(g_data.mlx_win, manage_inputs, &g_data);
	mlx_loop_hook(g_data.mlx, loop, &g_data);
	mlx_loop(g_data.mlx);
	return (0);
}
