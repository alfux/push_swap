/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:58:53 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 03:18:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stk	aff;

static int	orderedlst(t_stk *stk, t_list *frst, t_list *next, t_list **tmp)
{
	int		cmp;
	int		size;
	t_list	*buf;

	cmp = *(int *)frst->content;
	ft_lstadd_back(tmp, ft_lstnew(frst->content));
	size = 1;
	if (next)
		buf = next;
	else
		buf = stk->frst;
	while (buf != frst)
	{
		if (cmp < *(int *)buf->content)
		{
			ft_lstadd_back(tmp, ft_lstnew(buf->content));
			size++;
			cmp = *(int *)buf->content;
		}
		if (buf->next)
			buf = buf->next;
		else
			buf = stk->frst;
	}
	return (size);
}

static int	gol_from(t_stk *stk, t_list *frst, t_list **tmp)
{
	int		size;
	int		stmp;
	t_list	*buf;
	t_list	*ttmp;

	size = orderedlst(stk, frst, frst->next, tmp);
	ttmp = (void *)0;
	if (frst->next && frst->next->next)
		buf = frst->next->next;
	else
		buf = stk->frst;
	while (buf != frst)
	{
		stmp = orderedlst(stk, frst, buf, &ttmp);
		if (stmp > size)
		{
			ft_lstclear(tmp, (void *)0);
			*tmp = ttmp;
			ttmp = (void *)0;
			size = stmp;
		}
		else
			ft_lstclear(&ttmp, (void *)0);
		if (buf->next)
			buf = buf->next;
		else
			buf = stk->frst;
	}
	return (size);
}

t_list	*gol(t_stk *stk)
{
	t_list	*ext;
	t_list	*tmp;
	t_list	*buf;
	int		size;
	int		stmp;

	ext = (t_list *)0;
	tmp = (t_list *)0;
	size = gol_from(stk, stk->frst, &ext);
	buf = stk->frst->next;
	while (buf)
	{
		stmp = gol_from(stk, buf, &tmp);
		if (stmp > size)
		{
			ft_lstclear(&ext, (void *)0);
			ext = tmp;
			tmp = (t_list *)0;
			size = stmp;
		}
		else
			ft_lstclear(&tmp, (void *)0);
		buf = buf->next;
	}
	printstk(&aff);
	return (ext);
}
