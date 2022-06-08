/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:31:07 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 03:18:12 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_list	*saved_list(t_list *lst, int size, char bit)
{
	static int		saved_size;
	static t_list	*saved_lst;

	if (bit)
		return (saved_lst);
	if (size > saved_size)
	{
		saved_size = size;
		if (saved_lst)
			ft_lstclear(&saved_lst, (void *)0);
		saved_lst = ft_lstmap(lst, &identity, (void *)0);
	}
	return (lst);
}

static t_list	*rotate(t_stk *stk, t_list *list)
{
	if (list)
		return (list);
	return (stk->frst);
}

static void	lstdel_last(t_list **lst)
{
	if ((*lst)->next)
	{
		if ((*lst)->next->next)
			lstdel_last(&(*lst)->next);
		else
		{
			ft_lstdelone((*lst)->next, (void *)0);
			(*lst)->next = (void *)0;
		}
	}
	else
	{
		ft_lstdelone(*lst, (void *)0);
		*lst = (void *)0;
	}
}
/*
static void	printlst(t_list *lst)
{
	t_stk	stk;

	stk.frst = lst;
	printstk(&stk);
}
*/
static t_list	*gol_from(t_stk *stk, t_list *start, t_list *stop)
{
	static int		size;
	static t_list	*gol;
	int				n;
	t_list			*nxt;

	ft_lstadd_back(&gol, ft_lstnew(start->content));
	nxt = rotate(stk, start->next);
	n = 1;
	while ((size_t)n < stk->size - *(int *)start->content)
	{
		while (nxt != stop)
		{
				if (*(int *)nxt->content == *(int *)start->content + n)
				{
					size++;
					gol = gol_from(stk, nxt, stop);
					lstdel_last(&gol);
					size--;
				}
				nxt = rotate(stk, nxt->next);
		}
		nxt = rotate(stk, start->next);
		n++;
	}
	if (start != stop)
		return (saved_list(gol, size, 0));
	ft_lstclear(&gol, (void *)0);
	return (saved_list((void *)0, 0, 1));
}

t_list	*gol(t_stk *stk)
{
	return (gol_from(stk, stk->frst, stk->frst));
}
