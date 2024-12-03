/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:13 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:01:16 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

// define constants to have a more explicit name for inputs instead of numbers

# define ESC 65307 

# define UP_W 119
# define UP_W_A 65362

# define UP_S 115
# define UP_S_A 65364

# define UP_A 97
# define UP_A_A 65361

# define UP_D 100
# define UP_D_A 65363

// check if the tile is one the player can walk on
int	is_valid_target_tile(t_vector2i pos, t_game_data *data);

// there is a few reasons why the map could be invalid
int	process_map_error_code(int code, t_game_data *data);

// small method to clean 
int	clean_up(t_game_data *data);

// flip a bit to a specific value
int	set_bit(int *base, int mask, int new_value);

// define which chars are considered valid tiles
int	is_valid_id(char id);

#endif
