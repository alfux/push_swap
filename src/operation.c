/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:41:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/19 14:25:21 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	swpstk(t_stk *stk)
{
	t_list	*buf;

	if (stk->frst && stk->frst->next)
	{
		buf = stk->frst->next;
		stk->frst->next = buf->next;
		if (!buf->next)
			stk->last = stk->frst;
		buf->next = stk->frst;
		stk->frst = buf;
		return (1);
	}
	return (0);
}
