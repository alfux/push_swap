/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:18:37 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/17 21:49:53 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	choose(t_stk *a, t_stk *b, int *tab)
{
	t_list	*output;

	output = (t_list *)0;
	if (a->size > 6)
	{
		a->output = &output;
		a->output = &output;
		quickinsert(a, b, a->size);
		clnoutput(&output);
		printoutput(output, 0);
	}
	else
	{
		output = bestoutput(a->size, tab);
		clnoutput(&output);
		printoutput(output, 1);
	}
	ft_lstclear(&output, &free);
	clrstk(a);
	clrstk(b);
	free(tab);
}
