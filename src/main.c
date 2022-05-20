/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/20 15:27:24 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	printstk(t_stk *stk)
{
	t_list	*buf;

	buf = stk->frst;
	while (buf)
	{
		ft_printf("%5s", (char *)buf->content);
		buf = buf->next;
	}
}

t_stk	*getstk(int argc, char **argv)
{
	int		i;
	t_stk	*stk;

	i = 0;
	stk = ft_calloc(1, sizeof (t_stk));
	while (++i < argc)
	{
		stk->last = ft_lstnew((char *)(*(argv + i)));
		ft_lstadd_back(&stk->frst, stk->last);
	}
	return (stk);
}

void	clrstk(t_stk *stk)
{
	ft_lstclear(&stk->frst, (void *)0);
	stk->last = (void *)0;
	free(stk);
}

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	b = ft_calloc(1, sizeof (t_stk));
	a = getstk(argc, argv);
	printstk(a);
	ft_printf("\n");
	printstk(b);
	ft_printf("\n");
	ft_printf("----SWAP----\n");
	swpstk(a);
	printstk(a);
	ft_printf("\n");
	printstk(b);
	ft_printf("\n");
	ft_printf("------------\n");
	ft_printf("----PUSH----\n");
	pshstk(a, b);
	printstk(a);
	ft_printf("\n");
	printstk(b);
	ft_printf("\n");
	ft_printf("------------\n");
	ft_printf("----ROTA----\n");
	rotstk(a);
	printstk(a);
	ft_printf("\n");
	printstk(b);
	ft_printf("\n");
	ft_printf("------------\n");
	ft_printf("----RRTA----\n");
	rrtstk(a);
	pshstk(b, a);
	rrtstk(a);
	rrtstk(b);
	printstk(a);
	ft_printf("\n");
	printstk(b);
	ft_printf("\n");
	ft_printf("------------\n");
	clrstk(a);
	clrstk(b);
	return (0);
}
