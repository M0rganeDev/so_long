/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:59:46 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 13:59:49 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "so_long.h"

// simple method to figure out where the player is on the map,
// should data->player_pos be not set (at the start of the game)
void	figure_out_player_pos(t_game_data *data);

// check what key the player pressed and do stuff based on that
void	handle_player_inputs(int keycode, t_game_data *data);

void	update_player_pos(t_game_data *data);

#endif
