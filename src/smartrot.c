/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 17:44:59 by afuchs           ###   ########.fr       */
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
	if (first < a->size - first)
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

void	smartrr(t_stk *a, t_stk *b, int ia, int ib)
{
	t_list	**savout;
	int		moves;

	savout = a->output;
	a->output = (t_list **)0;
	b->output = (t_list **)0;
	moves = ft_minof(ft_abs(ia), ft_abs(ib));
	while (ia > 0 && moves--)
	{
		rr(a, b);
		addoutput(savout, "rr");
	}
	while (ia < 0 && moves--)
	{
		rrr(a, b);
		addoutput(savout, "rrr");
	}
	a->output = savout;
	b->output = savout;
	if (ft_abs(ia) > ft_abs(ib))
		smartrot(a, ia - ib);
	else
		smartrot(b, ib - ia);
}
