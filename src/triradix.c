/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triradix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/09 02:28:42 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	swtelem(t_stk *a, t_list *elem)
{
	int		first;
	t_list	*buf;

	first = 0;
	buf = a->frst;
	while (buf && buf != elem)
	{
		first++;
		buf = buf->next;
	}
	if ((size_t)first < a->size - first)
		return (first);
	return (first - a->size);
}

void	smartrot(t_stk *stk, int moves)
{
	if (moves >= 0)
		while (moves--)
			rotstk(stk);
	else
		while (moves++)
			rrtstk(stk);
}

static t_list	*first(char zo, t_stk *a, int bit)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && ((*(int *)buf->content >> bit) % 2) != zo)
		buf = buf->next;
	return (buf);
}

static void	steptwo(t_stk *a, t_stk *b, int bit)
{
	t_list	*one;
	t_list	*zero;

	one = first(1, a, bit);
	zero = first(0, a, bit);
	while (zero)
	{
		smartrot(a, swtelem(a, zero));
		pshstk(a, b);
		zero = first(0, a, bit);
	}
	smartrot(a, swtelem(a, one));
	while (b->size)
		pshstk(b, a);
}

void	triradix(t_stk *a, t_stk *b)
{
	int	bit;

	bit = 0;
	while (!aissorted(a))
	{
		steptwo(a, b, bit);
		bit++;
	}
}
