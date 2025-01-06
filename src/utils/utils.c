/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:00 by morgane          #+#    #+#             */
/*   Updated: 2025/01/06 08:56:48 by morgane          ###   ########.fr       */
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
