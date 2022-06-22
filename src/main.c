/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/22 15:01:27 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	errmsg(char b)
{
	if (b)
		return (0);
	return ((int)ft_putstr_l("Error\n", 2));
}

int	main(int argc, char **argv)
{
	int		*tab;
	t_stk	*a;
	t_stk	*b;

	if (argc < 2)
		return (1);
	if (!checkint(argc, argv) || checkint(argc, argv) == 2)
		return (errmsg(checkint(argc, argv)));
	tab = getints(&argc, argv + 1);
	if (!tab)
		return (errmsg(0));
	a = getstk(argc - 1, tab);
	b = ft_calloc(1, sizeof (t_stk));
	if (!a || !b)
	{
		if (a)
			clrstk(a);
		if (b)
			clrstk(b);
		free(tab);
		return (errmsg(0));
	}
	b->name = 'b';
	choose(a, b, tab);
	return (0);
}
