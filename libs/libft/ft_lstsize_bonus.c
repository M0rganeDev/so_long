/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:03 by morgane          #+#    #+#             */
/*   Updated: 2024/10/28 08:49:59 by morgane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		index;
	t_list	*tmp;

	if (!lst)
		return (0);
	index = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		++index;
	}
	return (index);
}
