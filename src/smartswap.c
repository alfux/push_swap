/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smartswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:26:46 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 06:07:39 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	aswp(t_stk *a)
{
	if (a && a->frst && a->frst->next
		&& *(int *)a->frst->next->content < *(int *)a->frst->content)
		swpstk(a);
}

void	bswp(t_stk *b)
{
	if (b && b->frst && b->frst->next 
		&& *(int *)b->frst->next->content > *(int *)b->frst->content)
		swpstk(b);
}
