/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:01:33 by morgane          #+#    #+#             */
/*   Updated: 2024/11/08 13:51:18 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(const char chr)
{
	return (chr == ' ' || chr == '\n' || chr == '\t' || chr == '\v'
		|| chr == '\f' || chr == '\r');
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str && ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	return (result * sign);
}
