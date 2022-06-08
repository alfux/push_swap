/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triradix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 05:18:13 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	step(t_stk *a, t_stk *b, int tri)
{
	int	i;
	int	buf;

	i = a->size;
	while (i--)
	{
		buf = (*(int *)a->frst->content / tri) % 3;
		if (buf == 2)
			rotstk(a);
		else
			pshstk(a, b);
	}
	i = b->size;
	while (i--)
	{
		buf = (*(int *)b->frst->content / tri) % 3;
		if (buf == 0)
			rotstk(b);
		else
			pshstk(b, a);
	}
	i = b->size;
	while (i--)
		pshstk(b, a);
}

static void	steptwo(t_stk *a, t_stk *b, int tri)
{
	int	i;
	int	buf;
	int	bdiff;

	i = a->size;
	bdiff = b->size;
	while (i--)
	{
		buf = (*(int *)a->frst->content / tri) % 2;
		if (!buf)
			pshstk(a, b);
		else
			rotstk(a);
	}
	i = b->size - bdiff;
	while (i--)
		pshstk(b, a);
}

void	triradix(t_stk *a, t_stk *b)
{
	int	tri;

	tri = 1;
	while (0)
	{
		step(a, b, tri);
		tri *= 3;
	}
	while (!aissorted(a))
	{
		steptwo(a, b, tri);
		tri *= 2;
	}
}
