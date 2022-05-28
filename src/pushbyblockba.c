/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbyblockba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:19:47 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/28 03:33:15 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ascendba(t_stk *a, t_stk *b, unsigned int n, int fst)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(int *)a->frst->content <= fst)
		{
			while (i++ < n)
				pshstk(b, a);
			fst = *(int *)a->frst->content;
		}
		else if (b->frst && *(int *)b->frst->content > *(int *)a->last->content)
		{
			pshstk(b, a);
			i++;
		}
		else
			rrtstk(a);
	}
	while (*(int *)a->frst->content != fst)
		rrtstk(a);
}

static void	dscendba(t_stk *a, t_stk *b, int lst)
{
	t_list			*buf;

	buf = a->frst;
	while (a->frst == buf)
	{
		buf = a->frst->next;
		if (b->frst && *(int *)a->frst->content > *(int *)b->frst->content)
			pshstk(b, a);
		else if (*(int *)a->frst->content == lst)
		{
			rotstk(a);
			pshstk(b, a);
		}
		else
			rotstk(a);
	}
}

void	pushbyblockba(t_stk *a, t_stk *b, unsigned int n)
{
	unsigned int	i;
	int				fst;
	int				lst;

	if (a->size)
	{
		fst = *(int *)a->frst->content;
		lst = *(int *)a->last->content;
		dscendba(a, b, lst);
		ascendba(a, b, n - 1, fst);
	}
	while (b->size != b->size % (2 * n))
	{
		lst = *(int *)b->frst->content;
		i = 0;
		while (i++ < n)
			pshstk(b, a);
		fst = *(int *)a->frst->content;
		dscendba(a, b, lst);
		ascendba(a, b, n - 1, fst);
	}
}
