/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:58:52 by morgane           #+#    #+#             */
/*   Updated: 2024/12/11 09:45:10 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

#if !IS_BONUS

// do jack shit as the executable literally dont have access 
// to enemy code in mandatory mode. I would have done it differently,
// should the norm allows it
//
// ideally :
//
// void tick_enemies(t_game_data *data)
// {
// 		int	i;
//
// 		(void)data;
// 		i = -1;
// 		#if IS_BONUS
//		// yes, you can do include in method like that
//		# include "../bonus/enemy.h" 
//		while (++i < data->enemy_count)
//			process_enemy_move(data, &data->enemies[i]);
// 		#endif
// }
// 
// but hey, we do what we must
// also, not being able to do includes in method is the reason why this file
// even exist. This is fucking stupid !
void	tick_enemies(t_game_data *data)
{
	(void)data;
}

// this function should not even be called outside of BONUS,
// but we need it anyway, as i'm pretty sure not having it will.
// break shit if my parser fuck something up.
void	spawn_enemies(t_game_data *data, t_vector2i pos)
{
	(void)data;
	(void)pos;
}

void	make_space_for_enemies(t_game_data *data)
{
	(void)data;
}

void	free_space(t_game_data *data)
{
	(void)data;
}

#endif
