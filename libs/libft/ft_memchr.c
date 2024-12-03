/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:34:04 by morgane          #+#    #+#             */
/*   Updated: 2024/10/23 15:14:07 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	while (size--)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		++s;
	}
	return ((void *)0);
}
