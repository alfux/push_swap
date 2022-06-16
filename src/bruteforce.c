/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:21:03 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 22:40:07 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	initstks(t_stk **a, t_stk **b, int size, int *tab)
{
	*a = getstk(size, tab);
	*b = ft_calloc(1, sizeof (t_stk));
	(*b)->name = 'b';
}

t_list	*bestoutput(int size, int *tab)
{
	t_stk	*a;
	t_stk	*b;

	initstks(&a, &b, size, tab);
}
