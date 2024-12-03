/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:41:34 by morgane          #+#    #+#             */
/*   Updated: 2024/10/21 09:18:08 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*linked;
	int		size_s1;
	int		size_s2;
	int		index;

	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	linked = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!linked)
		return (NULL);
	index = 0;
	while (*s1)
		linked[index++] = *s1++;
	while (*s2)
		linked[index++] = *s2++;
	linked[index] = '\0';
	return (linked);
}
