/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:02:45 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:02:48 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "../so_long.h"

typedef struct s_infos
{
	int	map_x;
	int	map_y;
	int	tmask;
	int	x;
	int	y;
}		t_infos;

# define ARE_COLLECTIBLES_ACCESSIBLE 1
# define IS_EXIT_ACCESSIBLE 2
# define MAX_FLOOD_STEP 20480

// load the map in memory
char	**read_map(char *path);

// determine how many lines are in the map
int		get_line_count(int fd);

// tries to make sure the map is valid
int		validate_map(t_game_data *data);

// check if the map has a breach that would
// allow the player to go out of bounds
int		map_leak_to_void(t_game_data *data, t_infos *infos);

// call the homemade floodfill to ensure
// player can access all collectibles
// as well as the exit.
// returns 0 if it cant.
int		is_exit_available(t_game_data *data, t_infos *infos);
#endif
