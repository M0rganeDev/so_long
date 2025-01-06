/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:30 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:00:34 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

static void	*second_process_flag(char flag, t_textures *textures)
{
	if ((flag & (LEFT_SIDE_OPEN | UP_SIDE_OPEN | DOWN_SIDE_OPEN
				| RIGHT_SIDE_OPEN)) == 0)
		return (textures->wall_full_all_sides);
	else if (flag == LEFT_SIDE_OPEN + UP_SIDE_OPEN)
		return (textures->wall_corner_top_left);
	else if (flag == LEFT_SIDE_OPEN + DOWN_SIDE_OPEN)
		return (textures->wall_corner_bottom_left);
	else if (flag == LEFT_SIDE_OPEN)
		return (textures->wall_side_left);
	else if (flag == UP_SIDE_OPEN)
		return (textures->wall_side_over);
	else if (flag == DOWN_SIDE_OPEN)
		return (textures->wall_side_under);
	else
		return (textures->wall_side_right);
}

static void	*third_process_flag(char flag, t_textures *textures)
{
	if (flag == (UP_SIDE_OPEN + DOWN_SIDE_OPEN))
		return (textures->wall_two_side_top_down);
	else if (flag == LEFT_SIDE_OPEN + RIGHT_SIDE_OPEN)
		return (textures->wall_two_sides_left_right);
	else if (flag == RIGHT_SIDE_OPEN)
		return (textures->wall_side_right);
	else if (flag == UP_SIDE_OPEN + RIGHT_SIDE_OPEN)
		return (textures->wall_corner_top_right);
	else
		return (textures->wall_empty_right);
}

static void	*process_flag(char flag, t_textures *textures)
{
	if (flag <= 10)
		return (second_process_flag(flag, textures));
	else if (flag <= 20)
		return (third_process_flag(flag, textures));
	else if (flag == UP_SIDE_OPEN + LEFT_SIDE_OPEN + RIGHT_SIDE_OPEN)
		return (textures->wall_empty_bottom);
	else if (flag == RIGHT_SIDE_OPEN + DOWN_SIDE_OPEN)
		return (textures->wall_corner_bottom_right);
	else if (flag == DOWN_SIDE_OPEN + LEFT_SIDE_OPEN + RIGHT_SIDE_OPEN)
		return (textures->wall_empty_top);
	else if (flag == UP_SIDE_OPEN + RIGHT_SIDE_OPEN + DOWN_SIDE_OPEN)
		return (textures->wall_empty_left);
	else
		return (textures->wall_empty_all_sides);
}

void	*determine_best_wall_tile(t_game_data *data, int x, int y)
{
	char	flag;
	char	**map;

	flag = 0;
	map = data->map_data;
	if (x == 0 || map[y][x - 1] != '1')
		flag ^= LEFT_SIDE_OPEN;
	if (y == 0 || map[y - 1][x] != '1')
		flag ^= UP_SIDE_OPEN;
	if (y == data->map_size.y - 1 || map[y + 1][x] != '1')
		flag ^= DOWN_SIDE_OPEN;
	if (x == data->map_size.x - 1 || map[y][x + 1] != '1')
		flag ^= RIGHT_SIDE_OPEN;
	return (process_flag(flag, &data->textures));
}
