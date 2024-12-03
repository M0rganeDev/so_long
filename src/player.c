/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:28 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 13:59:31 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "player.h"
#include "so_long.h"
#include "utils.h"

/**
 *	Util function that do stuff based on player inputs.

	@param tile_after_player_move : the tile the player moved to if
		it's a valid tile to stand on
 */
static void	action(t_game_data *data, char tile_after_player_move)
{
	if (tile_after_player_move == 'C')
	{
		--data->collectible_count;
		ft_printf("player has collected a collectible\n");
	}
	if (data->collectible_count == 0)
		*data->exit = 'E';
	else
		*data->exit = '0';
	if (*data->exit == 'E' && tile_after_player_move == 'E')
	{
		set_bit(&data->game_flags, GF_GAME_OBJECTIVE_WON, 1);
		ft_printf("player, your winner !\n");
	}
}

static void	update_player_pos_part_2(t_game_data *data, t_vector2i *old_pos)
{
	if (data->game_flags & GF_PLAYER_M_DIR)
	{
		if (!(data->game_flags & GF_PLAYER_M_INV))
		{
			if (is_valid_target_tile(vector_add(data->player_pos, 1), data))
				data->player_pos.x -= 1;
		}
		else if (is_valid_target_tile(vector_add(data->player_pos, 0), data))
			data->player_pos.x += 1;
	}
	action(data, data->map_data[data->player_pos.y][data->player_pos.x]);
	if (old_pos->x != data->player_pos.x || old_pos->y != data->player_pos.y)
	{
		data->map_data[data->player_pos.y][data->player_pos.x] = 'P';
		data->map_data[old_pos->y][old_pos->x] = '0';
		set_bit(&data->game_flags, GF_NEED_WORLD_REFRESH, 1);
	}
	else
		set_bit(&data->game_flags, GF_PLAYER_IS_MOVING, 0);
}

void	update_player_pos(t_game_data *data)
{
	t_vector2i	old_pos;

	old_pos = data->player_pos;
	if (!(data->game_flags & GF_PLAYER_M_DIR))
	{
		if (!(data->game_flags & GF_PLAYER_M_INV))
		{
			if (is_valid_target_tile(vector_add(data->player_pos, 3), data))
				data->player_pos.y -= 1;
		}
		else if (is_valid_target_tile(vector_add(data->player_pos, 2), data))
			data->player_pos.y += 1;
	}
	update_player_pos_part_2(data, &old_pos);
}

void	figure_out_player_pos(t_game_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_size.y)
	{
		x = -1;
		while (++x < data->map_size.x)
		{
			if (data->map_data[y][x] == 'P')
			{
				data->player_pos.x = x;
				data->player_pos.y = y;
				return ;
			}
		}
	}
}

void	handle_player_inputs(int keycode, t_game_data *data)
{
	set_bit(&data->game_flags, GF_PLAYER_IS_MOVING, 1);
	if (keycode == UP_W || keycode == UP_W_A)
		set_bit(&data->game_flags, GF_PLAYER_M_DIR | GF_PLAYER_M_INV,
			0);
	else if (keycode == UP_S || keycode == UP_S_A)
	{
		set_bit(&data->game_flags, GF_PLAYER_M_DIR, 0);
		set_bit(&data->game_flags, GF_PLAYER_M_INV, 1);
	}
	else if (keycode == UP_A || keycode == UP_A_A)
	{
		set_bit(&data->game_flags, (GF_NEED_WORLD_REFRESH
				| GF_PLAYER_M_DIR), 1);
		set_bit(&data->game_flags, (GF_PLAYER_M_INV | GF_PLAYER_M_INV_TXT), 0);
	}
	else if (keycode == UP_D || keycode == UP_D_A)
		set_bit(&data->game_flags,
			GF_NEED_WORLD_REFRESH | GF_PLAYER_M_INV_TXT
			| GF_PLAYER_M_INV | GF_PLAYER_M_DIR,
			1);
	else
		set_bit(&data->game_flags, GF_PLAYER_IS_MOVING, 0);
}
