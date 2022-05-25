/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:40:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/25 01:46:04 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	aissorted(t_stk *a, t_stk *b)
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

char	bissorted(t_stk *a, t_stk *b)
{
	t_list	*buf;

	if (b->frst && !a->frst)
	{
		buf = b->frst;
		while (buf->next)
		{
			if (*(int *)buf->next->content > *(int *)buf->content)
				return (0);
			buf = buf->next;
		}
		return (1);
	}
	return (0);
}
