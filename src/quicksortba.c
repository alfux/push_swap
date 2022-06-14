/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksortba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:28:56 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/14 18:53:07 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	novr(t_stk *a, t_list *elem)
{
	t_list	*buf;
	int		n;

	buf = a->frst;
	n = 0;
	while (buf && elem)
	{
		if (*(int *)buf->content > *(int *)elem->content)
			n++;
		buf = buf->next;
	}
	return (n);
}

static t_list	*median(t_stk *a, int blcksz)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && novr(a, buf) != blcksz / 2)
		buf = buf->next;
	return (buf);
}

static t_list	*clstovr(t_stk *a, t_list *median, int *moves)
{
	t_list	*buf;
	t_list	*first;
	t_list	*last;
	int		f;
	int		l;

	buf = a->frst;
	while (buf && *(int *)buf->content <= *(int *)median->content)
		buf = buf->next;
	first = buf;
	if (!first)
		return (first);
	while (buf)
	{
		if (*(int *)buf->content > *(int *)median->content)
			last = buf;
		buf = buf->next;
	}
	f = swtelem(a, first);
	l = swtelem(a, last);
	*moves = f;
	if (ft_abs(f) < ft_abs(l))
		return (first);
	*moves = l;
	return (last);
}

static void	pshovrmed(t_stk *a, t_stk *b, int blcksz)
{
	t_list	*med;
	t_list	*ovrmed;
	t_list	*first;
	int		moves;

	med = median(b, blcksz);
	ovrmed = clstovr(b, med, &moves);
	first = b->frst;
	while (first && *(int *)first->content > *(int *)med->content)
		first = first->next;
	while (ovrmed)
	{
		smartrot(b, moves);
		pshstk(b, a);
		ovrmed = clstovr(b, med, &moves);
	}
	smartrot(b, swtelem(b, first));
}

void	quicksortba(t_stk *a, t_stk *b, int blcksz, int iter)
{
	int	i;

	i = 0;
	if (!bblckissorted(b, blcksz))
	{
		pshovrmed(a, b, blcksz);
		quicksortba(a, b, blcksz - (blcksz / 2), iter);
		if (!ablckissorted(a, blcksz / 2))
			quicksortab(a, b, blcksz / 2, iter);
		while (i++ < blcksz / 2)
			pshstk(a, b);
	}
}
