/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:57:45 by morgane          #+#    #+#             */
/*   Updated: 2024/11/06 12:52:46 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*target;

	target = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!target)
		return (NULL);
	ft_strlcpy(target, src, ft_strlen(src) + 1);
	return (target);
}
