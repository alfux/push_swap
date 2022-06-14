/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:26:46 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/13 14:41:25 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	apreswp(t_stk *a, int med)
{
	if (*(int *)a->frst->next->content < med
		&& *(int *)a->frst->next->content < *(int *)a->frst->content)
		swpstk(a);
}

void	bpreswp(t_stk *b, int med)
{
	if (*(int *)b->frst->next->content > med
		&& *(int *)b->frst->next->content > *(int *)b->frst->content)
		swpstk(b);
}

void	bpstswp(t_stk *b)
{
	if (b->frst->next
		&& *(int *)b->frst->next->content > *(int *)b->frst->content)
		swpstk(b);
}

void	apstswp(t_stk *a)
{
	if (a->frst->next
		&& *(int *)a->frst->next->content < *(int *)a->frst->content)
		swpstk(a);
}
