/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tryout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:08:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 04:18:36 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	ss(t_stk *a, t_stk *b)
{
	return (swpstk(a) | swpstk(b));
}

char	rr(t_stk *a, t_stk *b)
{
	return (rotstk(a) | rotstk(b));
}

char	rrr(t_stk *a, t_stk *b)
{
	return (rrtstk(a) | rrtstk(b));
}

char	op(t_stk *a, t_stk *b, char *str)
{
	if (*str == 's' && *(str + 1) == 'a')
		return (swpstk(a));
	else if (*str == 's' && *(str + 1) == 'b')
		return (swpstk(b));
	else if (*str == 's' && *(str + 1) == 's')
		return (ss(a, b));
	else if (*str == 'p' && *(str + 1) == 'a')
		return (pshstk(b, a));
	else if (*str == 'p' && *(str + 1) == 'b')
		return (pshstk(a, b));
	else if (*str == 'r' && *(str + 1) == 'a')
		return (rotstk(a));
	else if (*str == 'r' && *(str + 1) == 'b')
		return (rotstk(b));
	else if (*str == 'r' && *(str + 1) == 'r' && !*(str + 2))
		return (rr(a, b));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		return (rrtstk(a));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		return (rrtstk(b));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'r')
		return (rrr(a, b));
	else
		return (0);
}

char	tryout(t_list *output, t_stk *a, t_stk *b)
{
	t_list	*buf;

	buf = output;
	while (buf && a && b)
	{
		op(a, b, (char *)buf->content);
		buf = buf->next;
	}
	if (aissorted(a) && !b->size)
		return (1);
	else
		return (0);
}
