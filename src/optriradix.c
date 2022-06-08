/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optriradix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 05:13:00 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 05:47:11 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	isingol(t_list *elem, t_list *ol)
{
	t_list	*nxt;

	nxt = ol;
	while (nxt)
	{
		if (elem->content == nxt->content)
			return (1);
		nxt = nxt->next;
	}
	return (0);
}

void	optriradix(t_stk *a, t_stk *b)
{
	t_list	*ol;
	int		i;

	ol = gol(a);
	i = a->size;
	while (i--)
	{
		if (isingol(a->frst, ol))
			pshstk(a, b);
		else
			rotstk(a);
	}
	triradix(a, b);
}
