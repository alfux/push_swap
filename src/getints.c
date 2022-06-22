/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/22 13:05:51 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	*splitargv(int *argc, char *str)
{
	char	**spl;
	int		size;
	int		*tab;

	spl = ft_split(str, ' ');
	size = 0;
	while (*(spl + size))
		size++;
	*argc = size + 1;
	if (*argc > 2)
		tab = getints(argc, spl);
	else
	{
		tab = ft_calloc(size, sizeof (int));
		if (tab)
			*tab = ft_atoi(*spl);
	}
	size = 0;
	while (*(spl + size))
		free(*(spl + size++));
	free(spl);
	return (tab);
}

int	*getints(int *argc, char **argv)
{
	int	i;
	int	j;
	int	*tab;

	if (*argc == 2)
		return (splitargv(argc, *argv));
	tab = ft_calloc(*argc - 1, sizeof (int));
	if (!tab)
		return (tab);
	i = -1;
	while (++i < *argc - 1)
	{
		*(tab + i) = ft_atoi(*(argv + i));
		j = -1;
		while (++j < i)
		{
			if (*(tab + j) == *(tab + i))
			{
				free(tab);
				return ((void *)0);
			}
		}
	}
	return (tab);
}
