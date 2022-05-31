/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:19:11 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/31 14:24:20 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	timsort(t_stk *a)
{
	while (!aissorted(a))
	{
		if (*(int *)a->frst->content > *(int *)a->frst->next->content
			&& *(int *)a->frst->next->content != a->sml)
			swpstk(a);
		rotstk(a);
	}
}
