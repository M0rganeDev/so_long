/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:33:51 by morgane          #+#    #+#             */
/*   Updated: 2024/11/05 13:45:00 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*buffer;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	buffer = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}
