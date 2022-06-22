/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/22 14:03:16 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	clrall(t_stk *a, t_stk *b, int *tab)
{
	clrstk(a);
	clrstk(b);
	free(tab);
	return (0);
}

static int	errmsg(char b)
{
	if (b)
		return (0);
	return ((int)ft_putstr_l("Error\n", 2));
}

static int	checker(t_stk *a, t_stk *b, int *tab)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strlen(str) > 0 && *(str + ft_strlen(str) - 1) != '\n')
		{
			free(str);
			return (clrall(a, b, tab) + errmsg(0));
		}
		if (op(a, b, str) == -1)
		{
			free(str);
			return (clrall(a, b, tab) + errmsg(0));
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
	if (aissorted(a) && !b->size)
		return (clrall(a, b, tab) + ft_printf("\033[32mOK\033[0m\n"));
	return (clrall(a, b, tab) + ft_printf("\033[31mKO\033[0m\n"));
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
	checker(a, b, tab);
	return (0);
}
