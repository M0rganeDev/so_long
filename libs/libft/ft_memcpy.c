/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:05:12 by morgane          #+#    #+#             */
/*   Updated: 2024/11/08 10:32:33 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)dest;
	while (n-- != 0)
	{
		*(unsigned char *)tmp = *(unsigned char *)src;
		++tmp;
		++src;
	}
	return (dest);
}
