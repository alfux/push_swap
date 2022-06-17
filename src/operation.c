/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:41:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 02:46:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	addoutput(t_list **output, char *str)
{
	if (output)
		ft_lstadd_back(output, ft_lstnew(ft_strdup(str)));
}

char	swpstk(t_stk *stk)
{
	t_list	*buf;

	if (stk && stk->frst && stk->frst->next)
	{
		buf = stk->frst;
		stk->frst = stk->frst->next;
		buf->next = stk->frst->next;
		stk->frst->next = buf;
		if (!stk->frst->next->next)
			stk->last = stk->frst->next;
		if (stk->name == 'a')
			addoutput(stk->output, "sa");
		if (stk->name == 'b')
			addoutput(stk->output, "sb");
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
		A->size--;
		B->size++;
		if (B->name == 'a')
			addoutput(B->output, "pa");
		if (B->name == 'b')
			addoutput(B->output, "pb");
		return (1);
	}
	return (0);
}

char	rotstk(t_stk *stk)
{
	if (stk && stk->frst && stk->frst->next)
	{
		stk->last->next = stk->frst;
		stk->last = stk->frst;
		stk->frst = stk->frst->next;
		stk->last->next = (void *)0;
		if (stk->name == 'a')
			addoutput(stk->output, "ra");
		if (stk->name == 'b')
			addoutput(stk->output, "rb");
		return (1);
	}
	return (0);
}

char	rrtstk(t_stk *stk)
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
			addoutput(stk->output, "rra");
		if (stk->name == 'b')
			addoutput(stk->output, "rrb");
		return (1);
	}
	return (0);
}
