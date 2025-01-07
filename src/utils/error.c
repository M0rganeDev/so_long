/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:00:10 by morgane           #+#    #+#             */
/*   Updated: 2025/01/07 08:20:51 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"
#include "utils.h"

int	ft_error(char *error, int status, t_game_data *data)
{
	ft_printf("\nError\n");
	ft_printf("%s\n\n", error);
	if (status != -2)
		clean_up(data, status);
	return (0);
}
