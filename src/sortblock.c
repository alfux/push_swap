/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:19:47 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/28 02:35:22 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sortbytwo(t_stk *a, t_stk *b)
{
	while (a->frst && a->frst->next)
	{
		if (*(int *)a->frst->content > *(int *)a->frst->next->content)
			swpstk(a);
		pshstk(a, b);
		pshstk(a, b);
	}
}

void	sortblock(t_stk *a, t_stk *b)
{
	int	two;

	two = 1;
	if (!aissorted(a, b))
	{
		sortbytwo(a, b);
		while (1)
		{
			two *= 2;
			if (bissorted(a, b))
				while (b->size)
					pshstk(b, a);
			else
				pushbyblockba(a, b, two);
			if (aissorted(a, b))
				break ;
			else
				pushbyblockab(a, b, 2 * two);
		}
	}
}
