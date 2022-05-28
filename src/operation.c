/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:41:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/28 03:48:12 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swpstk(t_stk *stk)
{
	void	*buf;

	if (stk && stk->frst && stk->frst->next)
	{
		buf = stk->frst->content;
		stk->frst->content = stk->frst->next->content;
		stk->frst->next->content = buf;
		ft_printf("s%c\n", stk->name);
	}
}

void	pshstk(t_stk *A, t_stk *B)
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
		A->size--;
		B->size++;
		ft_printf("p%c\n", B->name);
	}
}

void	rotstk(t_stk *stk)
{
	if (stk && stk->frst && stk->frst->next)
	{
		stk->last->next = stk->frst;
		stk->last = stk->frst;
		stk->frst = stk->frst->next;
		stk->last->next = (void *)0;
		ft_printf("r%c\n", stk->name);
	}
}

void	rrtstk(t_stk *stk)
{
	t_list	*buf;

	if (stk && stk->frst && stk->frst->next)
	{
		buf = stk->frst;
		while (buf->next->next)
			buf = buf->next;
		buf->next->next = stk->frst;
		stk->frst = buf->next;
		buf->next = (void *)0;
		stk->last = buf;
		ft_printf("rr%c\n", stk->name);
	}
}
