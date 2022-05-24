/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:19:47 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/24 18:05:23 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	issorted(t_stk *a, t_stk *b)
{
	t_list	*buf;

	if (a->frst && !b->frst)
	{
		buf = a->frst;
		while (buf->next)
		{
			if (*(int *)buf->next->content < *(int *)buf->content)
				return (0);
			buf = buf->next;
		}
		return (1);
	}
	return (0);
}

static void	ascent(t_stk *a, t_stk *b, unsigned int n, int fst)
{
//TOBECONTINUED
}

static void	dscent(t_stk *a, t_stk *b, unsigned int n)
{
	unsigned int	i;
	int				lst;
	int				fst;
	t_list			*buf;

	i = 0;
	lst = *(int *)b->frst->content;
	while (i++ < n)
		pshstk(b, a);
	fst = *(int *)a->frst->content;
	buf = a->frst;
	while (a->frst == buf)
	{
		buf = a->frst->next;
		if (*(int *)a->frst->content > *(int *)b->frst->content)
			pshstk(b, a);
		else if (*(int *)a->frst->content == lst)
		{
			rotstk(a);
			pshstk(b, a);
		}
		else
			rotstk(a);
	}
	ascent(a, b, n - 1, fst);
}

static void	sortbytwo(t_stk *a, t_stk *b)
{
	while (a->frst && a->frst->next)
	{
		if (*(int *)a->frst->content > *(int *)a->frst->next->content)
			swpstk(a);
		pshstk(a, b);
		pshstk(a, b);
	}
}

void	sortblock(t_stk *a, t_stk *b)
{
	if (issorted(a, b))
		ft_printf("C'est sorted lul\n");
	else
		ft_printf("nope\n");
	sortbytwo(a, b);
}
