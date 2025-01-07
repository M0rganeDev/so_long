/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:32:35 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 08:14:00 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include "mlx.h"
#include "utils.h"
#include <stdlib.h>

void	unload_font(t_game_data *data)
{
	ft_printf("Deleting font\n");
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
	ft_printf("Deleting ground tiles\n");
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

static void	delete_textures(t_game_data *data)
{
	ft_printf("Deleting game textures\n");
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
	delete_walls(data);
	unload_font(data);
}

void	clean_up(t_game_data *data, int before_init)
{
	static int	index = -1;

	ft_printf("Cleaning up my closet\n");
	if (before_init >= 0)
		delete_textures(data);
	if (before_init == 0)
	{
		ft_printf("deleting the window\n");
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
	}
	ft_printf("Deleting MLX context\n");
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (before_init != -1)
	{
		ft_printf("Deleting game data\n");
		free_space(data);
		while (++index < (int)data->map_size.y)
			free(data->map_data[index]);
		free(data->map_data);
	}
	ft_printf("everything was cleared properly, we can exit !\n");
	exit(0);
}

int	int_c_up(t_game_data *data)
{
	clean_up(data, 0);
	return (0);
}
