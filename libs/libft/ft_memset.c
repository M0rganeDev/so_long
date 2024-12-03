/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:07:45 by morgane          #+#    #+#             */
/*   Updated: 2024/11/06 12:46:15 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	++n;
	tmp = s;
	while (--n > 0)
		*tmp++ = (unsigned char)c;
	return (s);
}
