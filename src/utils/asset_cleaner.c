/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destroyer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:35 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 13:42:21 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "utils.h"

void    unload_font(t_game_data *data)
{
    mlx_destroy_image(data->mlx, data->textures.nbr_zero);
    mlx_destroy_image(data->mlx, data->textures.nbr_one);
    mlx_destroy_image(data->mlx, data->textures.nbr_two);
    mlx_destroy_image(data->mlx, data->textures.nbr_three);
    mlx_destroy_image(data->mlx, data->textures.nbr_four);
    mlx_destroy_image(data->mlx, data->textures.nbr_five);
    mlx_destroy_image(data->mlx, data->textures.nbr_six);
    mlx_destroy_image(data->mlx, data->textures.nbr_seven);
    mlx_destroy_image(data->mlx, data->textures.nbr_eight);
    mlx_destroy_image(data->mlx, data->textures.nbr_nine);
}

static void	delete_walls(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.wall_full_all_sides);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_all_sides);
	mlx_destroy_image(data->mlx, data->textures.wall_side_left);
	mlx_destroy_image(data->mlx, data->textures.wall_side_under);
	mlx_destroy_image(data->mlx, data->textures.wall_side_right);
	mlx_destroy_image(data->mlx, data->textures.wall_side_over);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_top_right);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_top_left);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_bottom_right);
	mlx_destroy_image(data->mlx, data->textures.wall_corner_bottom_left);
	mlx_destroy_image(data->mlx, data->textures.wall_two_sides_left_right);
	mlx_destroy_image(data->mlx, data->textures.wall_two_side_top_down);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_bottom);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_left);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_top);
	mlx_destroy_image(data->mlx, data->textures.wall_empty_right);
}

#include "ft_printf.h"

int	clean_up(t_game_data *data)
{
	int index;

	index = -1;
	mlx_destroy_image(data->mlx, data->textures.player);
	mlx_destroy_image(data->mlx, data->textures.player_left);
	mlx_destroy_image(data->mlx, data->textures.ground);
	mlx_destroy_image(data->mlx, data->textures.collectible);
	mlx_destroy_image(data->mlx, data->textures.exit);
	mlx_destroy_image(data->mlx, data->textures.debug);
	mlx_destroy_image(data->mlx, data->textures.enemy);
	mlx_destroy_image(data->mlx, data->textures.step_label);
	mlx_destroy_image(data->mlx, data->textures.collected);
	mlx_destroy_image(data->mlx, data->textures.slash);
	unload_font(data);
	delete_walls(data);
	while (++index < (int)data->map_size.y)
		free(data->map_data[index]);
	free(data->map_data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_space(data);
	exit(0);
	return (0);
}