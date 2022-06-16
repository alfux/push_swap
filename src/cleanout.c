/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 08:33:21 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 02:04:44 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rmpapb(t_list *start, t_list **prev, size_t n)
{
	size_t	pa;
	size_t	pb;

	pa = n;
	pb = n;
	while (start && (pa || pb))
	{
		if (pa && *((char *)start->content + 1) == 'a')
		{
			*prev = start->next;
			ft_lstdelone(start, &free);
			start = *prev;
			pa--;
		}
		else if (pb && *((char *)start->content + 1) == 'b')
		{
			*prev = start->next;
			ft_lstdelone(start, &free);
			start = *prev;
			pb--;
		}
		else
		{
			prev = &start->next;
			start = start->next;
		}
	}
}

static void	squeezep(t_list **buf, t_list **prev)
{
	size_t	pa;
	size_t	pb;

	pa = 0;
	pb = 0;
	while (*buf && *(char *)(*buf)->content == 'p')
	{
		if (*((char *)(*buf)->content + 1) == 'a')
			pa++;
		else
			pb++;
		*buf = (*buf)->next;
	}
	if (pa && pb)
		rmpapb(*prev, prev, ft_minof(pa, pb));
}

void	clnoutput(t_list **output)
{
	t_list	*buf;
	t_list	**prev;

	buf = *output;
	prev = output;
	while (buf)
	{
		if (*(char *)buf->content == 'p')
			squeezep(&buf, prev);
		else
		{
			prev = &buf->next;
			buf = buf->next;
		}
	}
}
