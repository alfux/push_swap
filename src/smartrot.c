/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:10 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 04:44:40 by afuchs           ###   ########.fr       */
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
