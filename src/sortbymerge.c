/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:19:47 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/31 12:49:15 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	twoksup(size_t n)
{
	int		k;
	char	p;

	k = 0;
	p = 1;
	while (n)
	{
		if (p && n != 1 && n % 2)
			p = 0;
		n /= 2;
		k++;
	}
	if (p)
		return (k - 1);
	return (k);
}

static void	sortbytwoa(t_stk *a, t_stk *b, int *two)
{
	size_t	i;
	t_list	*buf;

	buf = a->frst;
	while (buf && buf->next)
	{
		if (*(int *)buf->content > *(int *)buf->next->content)
		{
			i = -1;
			while (++i < a->size / 2)
			{
				if (*(int *)a->frst->content > *(int *)a->frst->next->content)
					swpstk(a);
				rotstk(a);
				rotstk(a);
			}
			if (a->size % 2)
				rotstk(a);
			break ;
		}
		buf = buf->next->next;
	}
	*two *= 2;
	pushbyblockab(a, b, *two);
}

static void	sortbytwob(t_stk *a, t_stk *b)
{
	while (a->frst && a->frst->next)
	{
		if (*(int *)a->frst->content > *(int *)a->frst->next->content)
			swpstk(a);
		pshstk(a, b);
		pshstk(a, b);
	}
}

void	sortbymerge(t_stk *a, t_stk *b)
{
	int	two;

	two = 1;
	if (!aissorted(a))
	{
		if (twoksup(a->size) % 2)
			sortbytwoa(a, b, &two);
		else
			sortbytwob(a, b);
		while (1)
		{
			two *= 2;
			if (bissorted(b) && aissorted(a)
				&& (!a->size || !b->size
				|| *(int *)a->frst->content > *(int *)b->frst->content))
					while (b->size)
						pshstk(b, a);
			else
				pushbyblockba(a, b, two);
			if (aissorted(a) && !b->size)
				break ;
			else
				pushbyblockab(a, b, 2 * two);
		}
	}
}
