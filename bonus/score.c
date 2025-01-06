/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 07:58:30 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 13:33:52 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"
#include "mlx.h"
#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include "ft_printf.h"

// this is so fucking stupid that 
// i'd rather do JS than explain why it even exist
static void	*get_texture_from_char(t_game_data *data, char number)
{
	if (number == '0')
		return (data->textures.nbr_zero);
	if (number == '1')
		return (data->textures.nbr_one);
	if (number == '2')
		return (data->textures.nbr_two);
	if (number == '3')
		return (data->textures.nbr_three);
	if (number == '4')
		return (data->textures.nbr_four);
	if (number == '5')
		return (data->textures.nbr_five);
	if (number == '6')
		return (data->textures.nbr_six);
	if (number == '7')
		return (data->textures.nbr_seven);
	if (number == '8')
		return (data->textures.nbr_eight);
	if (number == '9')
		return (data->textures.nbr_nine);
	return (data->textures.debug);
}

static void	draw_steps(t_game_data *data, int value, t_vector2i *origin)
{
	char	*score_as_text;
	int 	index;

	if (value < 0)
		value = 0;
	score_as_text = ft_itoa(value);
	index = -1;
	while (score_as_text[++index])
	{
		origin->x += (index * 26);
		mlx_put_image_to_window(data->mlx, data->mlx_win, get_texture_from_char(data, score_as_text[index]), origin->x, origin->y);
	}
	free(score_as_text);
}

static void	draw_collectible(t_game_data *data)
{
	t_vector2i origin;

	origin.x = 250;
	origin.y = 32;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->textures.collected, 0, 32);
	draw_steps(data, (data->base_collectible - data->collectible_count), &origin);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures.slash, origin.x + 26, 32);
	origin.x += 26 * 2;
	draw_steps(data, data->base_collectible, &origin);
}

void	draw_score(t_game_data *data)
{
	t_vector2i origin;

	origin.x = 250;
	origin.y = 0;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->textures.step_label, 0, 0);
	draw_steps(data, data->player_step, &origin);
	draw_collectible(data);
}