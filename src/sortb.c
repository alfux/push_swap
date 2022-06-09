/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:08:53 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/09 06:30:22 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rec(t_stk *a, t_stk *b, int *moves, t_list *med)
{
	smartrot(a, *moves);
	pshstk(a, b);
	insertsort(a, b, med);
}

static t_list	*next(t_stk *a, t_stk *b, int *moves, t_list *med)
{
	smartrot(a, *moves);
	pshstk(a, b);
	return (clstsub(a, med, moves));
}

void	insertsort(t_stk *a, t_stk *b, t_list *med)
{
	int		moves;
	t_list	*submed;

	while (*(int *)b->frst->content < *(int *)b->frst->next->content)
	{
		swpstk(b);
		if (*(int *)b->frst->content < *(int *)b->frst->next->next->content)
			break ;
		if (*(int *)b->frst->next->content <
			*(int *)b->frst->next->next->content)
		rotstk(b);
	}
	submed = clstsub(a, med, &moves);
	//Fonction smartrot quand il n'y a plus de submed
	while (!bissorted(b))
	{
		if (submed && *(int *)submed->content < *(int *)b->frst->content)
			rec(a, b, &moves, med);
		else if (submed && *(int *)submed->content < *(int *)b->last->content)
			submed = next(a, b, &moves, med);
		else
			rrtstk(b);
	}
}

void	insortb(t_stk *a, t_stk *b, t_list *med)
{
	if (b->size > 2 && *(int *)b->frst->content < *(int *)b->frst->next->content
			&& *(int *)b->frst->content > *(int *)b->frst->next->next->content)
		swpstk(b);
	else if (*(int *)b->frst->content < *(int *)b->last->content)
		rotstk(b);
	else if (!bissorted(b))
		insertsort(a, b, med);
}
