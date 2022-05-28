/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbyblockab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:19:47 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/28 03:33:35 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ascendab(t_stk *a, t_stk *b, unsigned int n, int fst)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(int *)b->frst->content >= fst)
		{
			while (i++ < n)
				pshstk(a, b);
			fst = *(int *)b->frst->content;
		}
		else if (a->frst && *(int *)a->frst->content < *(int *)b->last->content)
		{
			pshstk(a, b);
			i++;
		}
		else
			rrtstk(b);
	}
	while (*(int *)b->frst->content != fst)
		rrtstk(b);
}

static void	dscendab(t_stk *a, t_stk *b, int lst)
{
	t_list			*buf;

	buf = b->frst;
	while (b->frst == buf)
	{
		buf = b->frst->next;
		if (a->frst && *(int *)b->frst->content < *(int *)a->frst->content)
			pshstk(a, b);
		else if (*(int *)b->frst->content == lst)
		{
			rotstk(b);
			pshstk(a, b);
		}
		else
			rotstk(b);
	}
}

void	pushbyblockab(t_stk *a, t_stk *b, unsigned int n)
{
	unsigned int	i;
	int				fst;
	int				lst;

	if (b->size)
	{
		fst = *(int *)b->frst->content;
		lst = *(int *)b->last->content;
		dscendab(a, b, lst);
		ascendab(a, b, n - 1, fst);
	}
	while (a->size != a->size % (2 * n))
	{
		lst = *(int *)a->frst->content;
		i = 0;
		while (i++ < n)
			pshstk(a, b);
		fst = *(int *)b->frst->content;
		dscendab(a, b, lst);
		ascendab(a, b, n - 1, fst);
	}
}
