/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/27 21:39:24 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

struct					s_stk
{
	t_list	*frst;
	t_list	*last;
	size_t	size;
	char	name;
};
typedef struct s_stk	t_stk;

void	swpstk(t_stk *stk);
void	pshstk(t_stk *A, t_stk *B);
void	rotstk(t_stk *stk);
void	rrtstk(t_stk *stk);
char	checkint(int argc, char **argv);
void	pushbyblockba(t_stk *a, t_stk *b, unsigned int n);
void	pushbyblockab(t_stk *a, t_stk *b, unsigned int n);
void	sortblock(t_stk *a, t_stk *b);
char	aissorted(t_stk *a, t_stk *b);
char	bissorted(t_stk *a, t_stk *b);
void	printstk(t_stk *stk);
#endif
