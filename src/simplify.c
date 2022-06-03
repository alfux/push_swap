/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:32:18 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/03 18:51:11 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}
//AOPTI
static void	mimictab(int size, int *tab, int *ntab)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			swap(tab + i, tab + i + 1);
			mimictab(size, tab, ntab);
			swap(ntab + i, ntab + i + 1);
			break ;
		}
		else
			i++;
	}
}

int	*simplify_list(int size, int *tab)
{
	int	*ntab;
	int	i;

	ntab = ft_calloc(size, sizeof (int));
	i = -1;
	while (++i < size)
		*(ntab + i) = i;
	mimictab(size, tab, ntab);
	free(tab);
	return (ntab);
}
