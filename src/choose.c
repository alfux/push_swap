/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:18:37 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/22 16:59:04 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	modify(t_stk *a, t_stk *b, int size, int *tab)
{
	static int	i;
	int			j;
	t_list		*buf;
	t_list		**output;

	if (i < size)
	{
		output = a->output;
		clrstk(a);
		a = getstk(size, tab);
		a->output = output;
		buf = a->frst;
		j = 0;
		while (j++ < i)
			buf = buf->next;
		smartrot(a, swtelem(a, buf));
		swpstk(a);
		i++;
		choose(a, b, tab);
		return ;
	}
	printoutput(*a->output, 0);
	clrstk(a);
	clrstk(b);
	free(tab);
}

void	choose(t_stk *a, t_stk *b, int *tab)
{
	static t_list	*output;
	int				*firstcall;

	if (a->size > 6)
	{
		if (!a->output)
			a->output = &output;
		b->output = a->output;
		firstcall = quickinsert(a, b, a->size);
		*firstcall = 0;
		clnoutput(&output);
		if (a->size <= 100 && ft_lstsize(output) >= 700)
			return (modify(a, b, a->size, tab));
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
