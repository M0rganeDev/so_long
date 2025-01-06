/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:45:35 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 09:18:38 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy.h"
#include "so_long.h"
#include "utils.h"
#include <stdlib.h>
#include "ft_printf.h"

void	tick_enemies(t_game_data *data)
{
	int	i;

	if (data->enemy_count == 0)
		return ;
	i = -1;
	while (++i < data->enemy_count)
	{
		process_enemy_move(data, &data->enemies[i]);
	}
	set_bit(&data->game_flags, GF_NEED_WORLD_REFRESH, 1);
}

// yes, this wrap the enemy.c#spawn_enemy method
// yes this is stupid.
void	spawn_enemies(t_game_data *data, t_vector2i pos)
{
	spawn_enemy(data, pos);
}

void	init_data_enemy_space(t_game_data *data)
{
	if (data->enemy_count != 0)
		data->enemies = (t_enemy *)malloc(sizeof(t_enemy) * (data->enemy_count));
	else
		data->enemies = NULL;
}

void	make_space_for_enemies(t_game_data *data)
{
	init_data_enemy_space(data);
}

void	free_space(t_game_data *data)
{
	if (data->enemy_count != 0)
		free(data->enemies);
}
