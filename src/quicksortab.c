/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksortab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:28:56 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 06:23:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	nsub(t_stk *a, t_list *elem)
{
	t_list	*buf;
	int		n;

	buf = a->frst;
	n = 0;
	while (buf && elem)
	{
		if (*(int *)buf->content < *(int *)elem->content)
			n++;
		buf = buf->next;
	}
	return (n);
}

static t_list	*median(t_stk *a, int blcksz)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && nsub(a, buf) != blcksz / 2)
		buf = buf->next;
	return (buf);
}

static t_list	*clstsub(t_stk *a, t_list *median, int *moves)
{
	t_list	*buf;
	t_list	*first;
	t_list	*last;
	int		f;
	int		l;

	buf = a->frst;
	while (buf && *(int *)buf->content >= *(int *)median->content)
		buf = buf->next;
	first = buf;
	if (!first)
		return (first);
	while (buf)
	{
		if (*(int *)buf->content < *(int *)median->content)
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

static void	pshsubmed(t_stk *a, t_stk *b, int blcksz)
{
	t_list	*med;
	t_list	*submed;
	t_list	*first;
	int		moves;

	med = median(a, blcksz);
	submed = clstsub(a, med, &moves);
	first = a->frst;
	while (first && *(int *)first->content < *(int *)med->content)
		first = first->next;
	while (submed)
	{
		smartrot(a, moves);
		aswp(a);
		pshstk(a, b);
		bswp(b);
		submed = clstsub(a, med, &moves);
	}
	smartrot(a, swtelem(a, first));
}

void	quicksortab(t_stk *a, t_stk *b, int blcksz)
{
	int	i;

	i = 0;
	if (!ablckissorted(a, blcksz))
	{
		pshsubmed(a, b, blcksz);
		quicksortab(a, b, blcksz - (blcksz / 2));
		if (!bblckissorted(b, blcksz / 2))
			quicksortba(a, b, blcksz / 2);
		while (i++ < blcksz / 2)
			pshstk(b, a);
	}
}
