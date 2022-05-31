/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:40:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/31 12:48:30 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	aissorted(t_stk *a)
{
	t_list	*buf;

	buf = a->frst;
	while (buf && buf->next)
	{
		if (*(int *)buf->next->content < *(int *)buf->content)
			return (0);
		buf = buf->next;
	}
	return (1);
}

char	bissorted(t_stk *b)
{
	t_list	*buf;

	buf = b->frst;
	while (buf && buf->next)
	{
		if (*(int *)buf->next->content > *(int *)buf->content)
			return (0);
		buf = buf->next;
	}
	return (1);
}
