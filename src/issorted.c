/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:40:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/10 01:53:40 by afuchs           ###   ########.fr       */
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

char	ablckissorted(t_stk *a, int blcksz)
{
	t_list	*buf;
	int		i;

	buf = a->frst;
	i = 0;
	while (buf && buf->next && i < blcksz)
	{
		if (*(int *)buf->content > *(int *)buf->next->content)
			return (0);
		buf = buf->next;
		i++;
	}
	return (1);
}

char	bblckissorted(t_stk *b, int blcksz)
{
	t_list	*buf;
	int		i;

	buf = b->frst;
	i = 0;
	while (buf && buf->next && i < blcksz)
	{
		if (*(int *)buf->content < *(int *)buf->next->content)
			return (0);
		buf = buf->next;
		i++;
	}
	return (1);
}
