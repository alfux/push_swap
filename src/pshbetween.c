/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pshbetween.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:27:17 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 20:44:08 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	nbtw(t_stk *a, t_list *elem, int prev)
{
	t_list	*buf;
	int		n;

	buf = a->frst;
	n = 0;
	while (buf && elem)
	{
		if (*(int *)buf->content >= prev
			&& *(int *)buf->content < *(int *)elem->content)
			n++;
		buf = buf->next;
	}
	return (n);
}

static int	median(t_stk *a, int blcksz, int prev)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && nbtw(a, buf, prev) != blcksz / 2)
		buf = buf->next;
	return (*(int *)buf->content);
}

static t_list	*clstbtw(t_stk *a, int med, int prev)
{
	t_list	*buf;
	t_list	*fst;
	t_list	*lst;

	fst = a->frst;
	while (fst && (*(int *)fst->content < prev || *(int *)fst->content >= med))
		fst = fst->next;
	if (!fst)
		return ((t_list *)0);
	buf = a->frst;
	lst = buf;
	while (buf)
	{
		if (*(int *)buf->content >= prev && *(int *)buf->content < med)
			lst = buf;
		buf = buf->next;
	}
	if (ft_abs(swtelem(a, fst)) < ft_abs(swtelem(a, lst)))
		return (fst);
	return (lst);
}

int	pshbetween(t_stk *a, t_stk *b, int blcksz, int prev)
{
	t_list		*candidate;
	int			med;

	med = median(a, blcksz, prev);
	candidate = clstbtw(a, med, prev);
	while (candidate)
	{
		smartrot(a, swtelem(a, candidate));
		pshstk(a, b);
		candidate = clstbtw(a, med, prev);
	}
	return (med);
}
