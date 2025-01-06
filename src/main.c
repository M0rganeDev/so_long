/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:58:59 by morgane          #+#    #+#             */
/*   Updated: 2025/01/06 14:10:59 by morgane          ###   ########.fr       */
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
#include <X11/X.h>
#include "score.h"

int	loop(t_game_data *data)
{
	if ((data->game_flags & GF_NEED_WORLD_REFRESH) != 0)
		render_world(data);
	if ((data->game_flags & GF_GAME_OBJECTIVE_WON) != 0)
		clean_up(data);
	tick_enemies(data);
	draw_score(data);
	return (0);
}

int	manage_inputs(int keycode, t_game_data *data)
{
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
			++data->player_step;
			ft_printf("Player has taken %d steps.\n", data->player_step);
		}
	}
	else
		ft_printf("key pressed: %d\n\n", keycode);
	return (0);
}

void	setup_textures(t_game_data *data);

static t_vector2i	map_size(char **map)
{
	t_vector2i	_map;

	_map.x = ft_strlen(map[0]) * 32;
	_map.y = -1;
	while (map[++_map.y] != NULL)
	{
	}
	_map.y *= 32;
	_map.y += (32 * (IS_BONUS * 2));
	if (_map.x <= 400)
		_map.x = 400;
	return (_map);
}

// valgrind is being a cunt over this.
void	reset_all(t_game_data *data)
{
	data->enemy_count = 0;
	data->player_step = 0;
	data->base_collectible = 0;
	data->collectible_count = 0;
}

int	main(int argc, char **argv)
{
	t_game_data	g_data;
	int			is_valid;

	if (argc == 1 || !ft_strend(argv[1], ".ber"))
		return (0);
	g_data.game_flags = 0;
	g_data.mlx = mlx_init();
	setup_textures(&g_data);
	reset_all(&g_data);
	g_data.map_data = read_map(argv[1]);
	if (g_data.map_data == NULL)
		return (ft_printf("Error\n") - ft_strlen("Error\n"));
	g_data.mlx_win = mlx_new_window(g_data.mlx, map_size(g_data.map_data).x,
			map_size(g_data.map_data).y, "Hello world!");
	is_valid = validate_map(&g_data);
	figure_out_player_pos(&g_data);
	if (!is_valid)
		return (ft_printf("Error\n") - ft_strlen("Error\n"));
	mlx_key_hook(g_data.mlx_win, manage_inputs, &g_data);
	mlx_hook(g_data.mlx_win, DestroyNotify, ButtonPressMask, clean_up, &g_data);
	mlx_loop_hook(g_data.mlx, loop, &g_data);
	mlx_loop(g_data.mlx);
	return (0);
}
