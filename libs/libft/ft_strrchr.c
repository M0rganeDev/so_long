/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:35:13 by morgane          #+#    #+#             */
/*   Updated: 2024/11/08 10:27:58 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	cc;

	res = NULL;
	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			res = (char *)s;
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (res);
}
