/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:21:03 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/20 14:40:51 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	initstks(t_stk **a, t_stk **b, int size, int *tab)
{
	*a = getstk(size, tab);
	*b = ft_calloc(1, sizeof (t_stk));
	(*b)->name = 'b';
}

static char	**initops(void)
{
	char	**ops;

	ops = ft_calloc(12, sizeof (char *));
	*ops = ft_strdup("sa");
	*(ops + 1) = ft_strdup("sb");
	*(ops + 2) = ft_strdup("ss");
	*(ops + 3) = ft_strdup("pa");
	*(ops + 4) = ft_strdup("pb");
	*(ops + 5) = ft_strdup("ra");
	*(ops + 6) = ft_strdup("rb");
	*(ops + 7) = ft_strdup("rr");
	*(ops + 8) = ft_strdup("rra");
	*(ops + 9) = ft_strdup("rrb");
	*(ops + 10) = ft_strdup("rrr");
	return (ops);
}

char	revop(t_stk *a, t_stk *b, char *str)
{
	if (*str == 's' && *(str + 1) == 'a')
		return (swpstk(a));
	else if (*str == 's' && *(str + 1) == 'b')
		return (swpstk(b));
	else if (*str == 's' && *(str + 1) == 's')
		return (ss(a, b));
	else if (*str == 'p' && *(str + 1) == 'a')
		return (pshstk(a, b));
	else if (*str == 'p' && *(str + 1) == 'b')
		return (pshstk(b, a));
	else if (*str == 'r' && *(str + 1) == 'a')
		return (rrtstk(a));
	else if (*str == 'r' && *(str + 1) == 'b')
		return (rrtstk(b));
	else if (*str == 'r' && *(str + 1) == 'r'
		&& (!*(str + 2) || *(str + 2) == '\n'))
		return (rrr(a, b));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		return (rotstk(a));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		return (rotstk(b));
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'r')
		return (rr(a, b));
	else
		return (0);
}

t_list	*trials(t_stk *a, t_stk *b, char **ops, int range)
{
	static t_list	*output;
	int				i;

	if (!range)
		return ((t_list *)0);
	i = -1;
	while (*(ops + ++i))
	{
		if (op(a, b, *(ops + i)))
		{
			if (aissorted(a) && !b->size)
			{
				addoutput(&output, *(ops + i));
				return (output);
			}
			else if (trials(a, b, ops, range - 1))
			{
				addoutput(&output, *(ops + i));
				return (output);
			}
			else
				revop(a, b, *(ops + i));
		}
	}
	return ((t_list *)0);
}

t_list	*bestoutput(int size, int *tab)
{
	t_stk	*a;
	t_stk	*b;
	t_list	*output;
	char	**ops;
	int		i;

	initstks(&a, &b, size, tab);
	ops = initops();
	output = (t_list *)0;
	i = 0;
	if (!aissorted(a))
		while (!output)
			output = trials(a, b, ops, ++i);
	i = 0;
	while (*(ops + i))
		free(*(ops + i++));
	free(ops);
	clrstk(a);
	clrstk(b);
	return (output);
}
