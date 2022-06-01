/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:19:11 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/01 02:20:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	shortcycle(t_stk *a)
{
	size_t	k;
	t_list	*buf;

	buf = a->frst;
	k = 0;
	while (*(int *)buf->content != a->sml)
	{
		buf = buf->next;
		k++;
	}
	if (k <= a->size - k)
		while (k--)
			rotstk(a);
	else
		while (a->size - k++)
			rrtstk(a);
}

static char	iscyclesort(t_stk *a)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && buf->next)
	{
		if (!(*(int *)buf->content == a->lrg
				&& *(int *)buf->next->content == a->sml)
			&& *(int *)buf->content > *(int *)buf->next->content)
			return (0);
		buf = buf->next;
	}
	return (1);
}

void	timsort(t_stk *a)
{
	while (!aissorted(a))
	{
		if (*(int *)a->frst->content > *(int *)a->frst->next->content
			&& *(int *)a->frst->next->content != a->sml)
			swpstk(a);
		else
			rotstk(a);
	}
}

void	bmrgtimsort(t_stk *a)
{
	while (!aissorted(a))
	{
		if (*(int *)a->frst->content == a->lrg
			&& *(int *)a->last->content == a->sml && a->size > 3)
			rrtstk(a);
		if (*(int *)a->frst->content > *(int *)a->frst->next->content
			&& (*(int *)a->frst->next->content != a->sml
				|| *(int *)a->frst->content != a->lrg))
			swpstk(a);
		else if (*(int *)a->frst->content == a->sml
			&& *(int *)a->frst->next->content == a->lrg)
			swpstk(a);
		else
			rotstk(a);
		while (*(int *)a->frst->content < *(int *)a->last->content
			&& (*(int *)a->frst->content != a->sml
				|| *(int *)a->last->content != a->lrg))
		{
			rrtstk(a);
			swpstk(a);
		}
		if (iscyclesort(a))
			shortcycle(a);
	}
}
