/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:46:15 by morgane          #+#    #+#             */
/*   Updated: 2024/11/05 13:45:29 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*val;
	size_t	total;

	total = count * size;
	if ((count > 0) && (size > total / count))
		return (NULL);
	val = malloc(total);
	if (!val)
		return (NULL);
	ft_bzero(val, total);
	return (val);
}
