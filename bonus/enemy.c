/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:44:36 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 09:13:51 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"
#include "ft_printf.h"
#include "player.h"
#include "so_long.h"
#include "utils.h"

static void	move(t_game_data *data, t_enemy *enemy, t_vector2i pos)
{
	data->map_data[pos.y][pos.x] = 'F';
	data->map_data[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos = pos;
}

static void	_internal_move(t_game_data *data, t_enemy *enemy, t_vector2i pos)
{
	if ((enemy->dir & IS_MOVING_INVERTED_BIT) != 0)
	{
		if (data->map_data[pos.y][pos.x + 1] != '1')
			move(data, enemy, vector_add_lit(pos, 1, 0));
		else
			set_bit(&enemy->dir, IS_MOVING_INVERTED_BIT, 0);
		return ;
	}
	if (data->map_data[pos.y][pos.x - 1] != '1')
		move(data, enemy, vector_add_lit(pos, -1, 0));
	else
		set_bit(&enemy->dir, IS_MOVING_INVERTED_BIT, 1);
}

static void	internal_move(t_game_data *data, t_enemy *enemy, t_vector2i pos)
{
	if ((enemy->dir & MOVE_Y_BIT) != 0)
	{
		if ((enemy->dir & IS_MOVING_INVERTED_BIT) != 0)
		{
			if (data->map_data[pos.y + 1][pos.x] != '1')
				move(data, enemy, vector_add_lit(pos, 0, 1));
			else
				set_bit(&enemy->dir, IS_MOVING_INVERTED_BIT, 0);
			return ;
		}
		if (data->map_data[pos.y - 1][pos.x] != '1')
			move(data, enemy, vector_add_lit(pos, 0, -1));
		else
			set_bit(&enemy->dir, IS_MOVING_INVERTED_BIT, 1);
		return ;
	}
	_internal_move(data, enemy, pos);
}

void	process_enemy_move(t_game_data *data, t_enemy *enemy)
{
	t_vector2i	pos;
	
	if (data->enemy_count == 0)
		return ;
	//ft_printf("test\n");
	if (--enemy->mercy_frame > 0)
		return ;
	pos = enemy->pos;
	enemy->mercy_frame = ENEMY_WAIT_FRAME;
	internal_move(data, enemy, pos);
	action(data, data->map_data[data->player_pos.y][data->player_pos.x]);
}

int	spawn_enemy(t_game_data *data, t_vector2i pos)
{
	static int	total = 0;
	t_enemy		enemy;

	if (total >= data->enemy_count)
		return (1);
	//ft_printf("spawning enemy at {.x:%d,.y:%d} (%d/%d)\n", pos.x, pos.y, total, data->enemy_count);
	enemy.pos = pos;
	enemy.speed = ENEMY_DEFAULT_SPEED;
	if (data->map_data[pos.y + 1][pos.x] == '1' ||
		data->map_data[pos.y - 1][pos.x] == '1')
		set_bit(&enemy.dir, MOVE_Y_BIT, 1);
	else
		set_bit(&enemy.dir, MOVE_Y_BIT, 0);
	enemy.mercy_frame = ENEMY_WAIT_FRAME;
	if (enemy.dir == -1)
		return (0);
	data->enemies[total] = enemy;
	++total;
	return (0);
}
