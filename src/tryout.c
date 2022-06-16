/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tryout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:08:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 22:00:56 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ss(t_stk *a, t_stk *b)
{
	swpstk(a);
	swpstk(b);
}

static void	rr(t_stk *a, t_stk *b)
{
	rotstk(a);
	rotstk(b);
}

static void	rrr(t_stk *a, t_stk *b)
{
	rrtstk(a);
	rrtstk(b);
}

void op(char *str, t_stk *a, t_stk *b)
{
	if (*str == 's' && *(str + 1) == 'a')
		swpstk(a);
	else if (*str == 's' && *(str + 1) == 'b')
		swpstk(b);
	else if (*str == 's' && *(str + 1) == 's')
		ss(a, b);
	else if (*str == 'p' && *(str + 1) == 'a')
		pshstk(b, a);
	else if (*str == 'p' && *(str + 1) == 'b')
		pshstk(a, b);
	else if (*str == 'r' && *(str + 1) == 'a')
		rotstk(a);
	else if (*str == 'r' && *(str + 1) == 'b')
		rotstk(b);
	else if (*str == 'r' && *(str + 1) == 'r' && !*(str + 2))
		rr(a, b);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		rrtstk(a);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		rrtstk(b);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'r')
		rrr(a, b);
	else
		return ;
}

char	tryout(t_list *output, t_stk *a, t_stk *b)
{
	t_list	*buf;

	buf = output;
	while (buf && a && b)
	{
		op((char *)buf->content, a, b);
		buf = buf->next;
	}
	if (aissorted(a) && !b->size)
		return (1);
	else
		return (0);
}
