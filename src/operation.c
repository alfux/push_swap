/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:41:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/14 19:53:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	addoutput(t_stk *stk, char *str)
{
	ft_lstadd_back(stk->output, ft_lstnew(ft_strdup(str)));
}

void	swpstk(t_stk *stk)
{
	t_list	*buf;

	if (stk && stk->frst && stk->frst->next)
	{
		buf = stk->frst;
		stk->frst = stk->frst->next;
		buf->next = stk->frst->next;
		stk->frst->next = buf;
		ft_printf("s%c\n", stk->name);
		if (stk->name == 'a')
			addoutput(stk, "sa");
		if (stk->name == 'b')
			addoutput(stk, "sb");
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
		if (B->name == 'a')
			addoutput(B, "pa");
		if (B->name == 'b')
			addoutput(B, "pb");
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
		if (stk->name == 'a')
			addoutput(stk, "ra");
		if (stk->name == 'b')
			addoutput(stk, "rb");
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
		if (stk->name == 'a')
			addoutput(stk, "rra");
		if (stk->name == 'b')
			addoutput(stk, "rrb");
	}
}
