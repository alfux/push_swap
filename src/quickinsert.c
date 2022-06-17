/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:52:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 20:54:03 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//Maybe adjust with median
static int	swtinsert(t_stk *a, t_list *elem)
{
	t_list	*buf;
	t_list	*candidate;

	buf = a->frst;
	if (*(int *)elem->content < *(int *)buf->content
		&& *(int *)elem->content > *(int *)a->last->content)
		return (0);
	candidate = buf->next;
	while (candidate)
	{
		if (*(int *)elem->content < *(int *)candidate->content
			&& *(int *)elem->content > *(int *)buf->content)
			return (swtelem(a, candidate));
		buf = candidate;
		candidate = candidate->next;
	}
	buf = a->frst;
	candidate = buf;
	while (buf)
	{
		if (*(int *)candidate->content > *(int *)buf->content)
			candidate = buf;
		buf = buf->next;
	}
	return (swtelem(a, candidate));
}

static void	assign(int *bf, int *chp, size_t *moves)
{
	if (bf[0] * bf[1] >= 0)
	{
		if (ft_maxof(ft_abs(bf[0]), ft_abs(bf[1])) < *moves)
		{
			chp[0] = bf[0];
			chp[1] = bf[1];
			*moves = ft_maxof(ft_abs(bf[0]), ft_abs(bf[1]));
		}
	}
	else if (ft_abs(bf[0]) + ft_abs(bf[1]) < *moves)
	{
		chp[0] = bf[0];
		chp[1] = bf[1];
		*moves = ft_abs(bf[0]) + ft_abs(bf[1]);
	}
}

static void	cheapest(t_stk *a, t_stk *b)
{
	t_list	*buf;
	int		bf[2];
	int		chp[2];
	size_t		moves;

	buf = b->frst;
	bf[0] = 0;
	bf[1] = 0;
	chp[0] = b->size;
	chp[1] = a->size;
	moves = chp[0] + chp[1];
	while (buf)
	{
		bf[0] = swtelem(b, buf);
		bf[1] = swtinsert(a, buf);
		assign(bf, chp, &moves);
		buf = buf->next;
	}
	if (chp[0] * chp[1] > 0)
		smartrr(a, b, chp[1], chp[0]);
	else
	{
		smartrot(a, chp[1]);
		smartrot(b, chp[0]);
	}
}

static t_list	*findlargest(t_stk *b)
{
	t_list	*buf;
	t_list	*largest;

	buf = b->frst;
	largest = b->frst;
	while (buf)
	{
		if (*(int *)largest->content < *(int *)buf->content)
			largest = buf;
		buf = buf->next;
	}
	return (largest);
}

void	quickinsert(t_stk *a, t_stk *b, int blcksz)
{
	t_list		*lrgst;
	static int	prev;
	static int	firstcall;

	if (aissorted(a))
		return ;
	if (!firstcall)
	{
		firstcall++;
		prev = pshbetween(a, b, blcksz, a->sml);
	}
	else
		prev = pshbetween(a, b, blcksz, prev);
	lrgst = findlargest(b);
	while (b->size)
	{
		cheapest(a, b);
		pshstk(b, a);
	}
	if (iscyclesort(a))
	{
		lrgst = findlargest(a);
		smartrot(a, swtelem(a, lrgst) + 1);
	}
	quickinsert(a, b, blcksz - (blcksz / 2));
}
