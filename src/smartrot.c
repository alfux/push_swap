/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triradix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/14 18:40:01 by afuchs           ###   ########.fr       */
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
