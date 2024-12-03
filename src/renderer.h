/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:18 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:00:21 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "so_long.h"
# include <stdlib.h>

# define LEFT_SIDE_OPEN 2
# define UP_SIDE_OPEN 4
# define DOWN_SIDE_OPEN 8
# define RIGHT_SIDE_OPEN 16

void	*determine_best_wall_tile(t_game_data *data, int x, int y);
void	render_world(t_game_data *data);
void	render_tile(t_game_data *data, void *texture, int x, int y);
void	*load_texture(void *mlx, char *path);
void	*texture_from_id(t_textures texture, char id, t_game_data *data,
			t_vector2i pos);
#endif
