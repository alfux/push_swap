/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:31:07 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 05:04:20 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	lstdel_last(t_list **lst)
{
	if (lst && *lst && (*lst)->next)
	{
		if ((*lst)->next->next)
			lstdel_last(&(*lst)->next);
		else
		{
			ft_lstdelone((*lst)->next, (void *)0);
			(*lst)->next = (void *)0;
		}
	}
	else if (lst && *lst)
	{
		ft_lstdelone(*lst, (void *)0);
		*lst = (void *)0;
	}
}
