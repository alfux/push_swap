/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:41:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/19 21:32:53 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	swpstk(t_stk *stk)
{
	void	*buf;

	if (stk && stk->frst && stk->frst->next)
	{
		buf = stk->frst->content;
		stk->frst->content = stk->frst->next->content;
		stk->frst->next->content = buf;
		return (1);
	}
	return (0);
}

char	pshstk(t_stk *A, t_stk *B)
{
	t_list	*buf;

	if (A && B && A->frst)
	{
		buf = A->frst;
		A->frst = A->frst->next;
		buf->next = B->frst;
		B->frst = buf;
		if (!B->last)
			B->last = B->frst;
		if (!A->frst)
			A->last = (void *)0;
		return (1);
	}
	return (0);
}

char	rotstk(t_stk stk)
{
	//A SUIVRE
}
