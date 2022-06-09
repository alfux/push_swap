/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:28:56 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/09 06:27:59 by afuchs           ###   ########.fr       */
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

static t_list	*median(t_stk *a)
{
	t_list	*buf;
	int		n;

	buf = a->frst;
	n = 0;
	while (buf && nsub(a, buf) != a->size / 2)
		buf = buf->next;
	return (buf);
}

t_list	*clstsub(t_stk *a, t_list *median, int *moves)
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

static void	pshsubmed(t_stk *a, t_stk *b)
{
	t_list	*med;
	t_list	*submed;
	int		moves;

	med = median(a);
	submed = clstsub(a, med, &moves);
	while (submed)
	{
		smartrot(a, moves);
		pshstk(a, b);
		insortb(a, b, med);
		submed = clstsub(a, med, &moves);
	}
}

void	quicksort(t_stk *a, t_stk *b)
{
	while (a->size > 1)
		pshsubmed(a, b);
	while (b->size)
		pshstk(b, a);
}
