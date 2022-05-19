/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:46:30 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/19 14:30:00 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	stackA;
	t_list	prems;
	t_list	deuz;
	int		tab[] = {1, 2, 3, 4};

	stackA.frst = &prems;
	stackA.last = &deuz;
	prems.content = tab;
	prems.next = &deuz;
	deuz.content = tab + 1;
	deuz.next = (void *)0;
	ft_printf("%i\n%i\nLAST: %i\n", *(int *)stackA.frst->content, 
		*(int *)stackA.frst->next->content,
		*(int *)stackA.last->content);
	swpstk(&stackA);
	ft_printf("%i\n%i\nLAST: %i\n", *(int *)stackA.frst->content, 
		*(int *)stackA.frst->next->content,
		*(int *)stackA.last->content);
	(void)argc;
	(void)argv;
	return (0);
}
