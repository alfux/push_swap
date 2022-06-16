/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 06:10:28 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	printstk(t_stk *stk)
{
	t_list	*buf;

	buf = stk->frst;
	ft_printf("--------------Stack-%c-%i----------------------------------\n",
		stk->name, stk->size);
	while (buf)
	{
		ft_printf("%4i", *(int *)buf->content);
		buf = buf->next;
	}
	ft_printf("\n---------------------------------------------------------\n");
}

static void	printoutput(t_list *output)
{
	while (output)
	{
		ft_printf("%s\n", (char *)output->content);
		output = output->next;
	}
}

static int	*getints(int argc, char **argv)
{
	int	i;
	int	j;
	int	*tab;

	tab = ft_calloc(argc - 1, sizeof (int));
	if (!tab)
		return (tab);
	i = 0;
	while (i < argc - 1)
	{
		*(tab + i) = ft_atoi(*(argv + i + 1));
		j = 0;
		while (j < i)
		{
			if (*(tab + j) == *(tab + i))
			{
				free(tab);
				return ((void *)0);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static t_stk	*getstk(int size, int *tab)
{
	int		i;
	t_stk	*stk;

	i = -1;
	stk = ft_calloc(1, sizeof (t_stk));
	if (!stk)
	{
		free(tab);
		return (stk);
	}
	while (++i < size)
	{
		stk->last = ft_lstnew((int *)(tab + i));
		ft_lstadd_back(&stk->frst, stk->last);
		if (!i || *(int *)stk->last->content < stk->sml)
			stk->sml = *(int *)stk->last->content;
		if (!i || *(int *)stk->last->content > stk->lrg)
			stk->lrg = *(int *)stk->last->content;
	}
	stk->size = size;
	stk->name = 'a';
	return (stk);
}

static void	clrstk(t_stk *stk)
{
	ft_lstclear(&stk->frst, (void *)0);
	ft_lstclear(stk->output, &free);
	stk->last = (void *)0;
	free(stk);
}

int	main(int argc, char **argv)
{
	int				*tab;
	t_stk			*a;
	t_stk			*b;
	static t_list	*output;

	if (argc <= 2)
		return (1);
	if (!checkint(argc, argv))
		return (ft_printf("Error\n"));
	tab = getints(argc, argv);
	if (!tab)
		return (ft_printf("Error\n"));
	a = getstk(argc - 1, tab);
	b = ft_calloc(1, sizeof (t_stk));
	b->name = 'b';
	if (!a || !b)
		return (ft_printf("Error\n"));
	a->output = &output;
	b->output = &output;
	quicksortab(a, b, a->size);
	clnoutput(a->output);
	printoutput(*a->output);
	clrstk(a);
	clrstk(b);
	free(tab);
	return (0);
}
