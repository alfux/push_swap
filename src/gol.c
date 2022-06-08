/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:31:07 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 05:05:47 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
static void	printlst(t_list *lst)
{
	t_stk	stk;

	stk.frst = lst;
	printstk(&stk);
}
*/
static t_list	*saved_list(t_list *lst, int size, char bit)
{
	static int		saved_size;
	static t_list	*saved_lst;
	t_list			*reset;

	if (bit)
	{
		reset = saved_lst;
		saved_lst = (void *)0;
		saved_size = 0;
		return (reset);
	}
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

static t_list	*creturn(t_list *start, t_list *stop, t_list **gol, int *size)
{
	if (start != stop)
		return (saved_list(*gol, *size, 0));
	ft_lstclear(gol, (void *)0);
	*size = 0;
	return (saved_list((void *)0, 0, 1));
}

static t_list	*gol_from(t_stk *stk, t_list *start, t_list *stop)
{
	static int		size;
	static t_list	*gol;
	int				n;
	t_list			*nxt;

	ft_lstadd_back(&gol, ft_lstnew(start->content));
	nxt = rotate(stk, start->next);
	n = 0;
	while ((size_t)(++n) < stk->size - *(int *)start->content)
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
	}
	return (creturn(start, stop, &gol, &size));
}

t_list	*gol(t_stk *stk)
{
	t_list	*buf;
	t_list	*save;
	t_list	*new;
	int		size;
	int		nsize;

	save = gol_from(stk, stk->frst, stk->frst);
	size = ft_lstsize(save);
	buf = stk->frst->next;
	while (buf)
	{
		new = gol_from(stk, buf, buf);
		nsize = ft_lstsize(new);
		if (nsize > size)
		{
			ft_lstclear(&save, (void *)0);
			save = new;
			size = nsize;
		}
		buf = buf->next;
	}
	return (save);
}
