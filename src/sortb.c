/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:08:53 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/09 04:41:21 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	insertsort(t_stk *a, t_stk *b)
{
//HERE
}

void	insortb(t_stk *a, t_stk *b)
{
	if (b->size > 2 && *(int *)b->frst->content < *(int *)b->frst->next->content
			&& *(int *)b->frst->content > *(int *)b->frst->next->next->content)
		swpstk(b);
	else if (*(int *)b->frst->content < *(int *)b->last->content)
		rotstk(b);
	else
		insertsort(a, b);
}
