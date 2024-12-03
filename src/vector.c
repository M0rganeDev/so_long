/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:28 by morgane          #+#    #+#             */
/*   Updated: 2024/12/03 14:01:31 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector2i	vector_add_lit(t_vector2i base, int x, int y)
{
	base.x += x;
	base.y += y;
	return (base);
}

t_vector2i	vector_add(t_vector2i base, int flag)
{
	if (flag == 0)
		base.x += 1;
	else if (flag == 1)
		base.x -= 1;
	if (flag == 2)
		base.y += 1;
	else if (flag == 3)
		base.y -= 1;
	return (base);
}
