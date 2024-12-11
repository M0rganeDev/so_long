/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:17:30 by morgane           #+#    #+#             */
/*   Updated: 2024/12/11 10:42:47 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "so_long.h"

int		spawn_enemy(t_game_data *data, t_vector2i pos);

void	process_enemy_move(t_game_data *data, t_enemy *enemy);

int		free_enemy(t_enemy *enemy);

void	init_data_enemy_space(t_game_data *data);
#endif
