/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/08 05:47:06 by afuchs           ###   ########.fr       */
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
	int		lrg;
	int		sml;
};
typedef struct s_stk	t_stk;

void	swpstk(t_stk *stk);
void	pshstk(t_stk *A, t_stk *B);
void	rotstk(t_stk *stk);
void	rrtstk(t_stk *stk);
char	checkint(int argc, char **argv);
void	ascendba(t_stk *a, t_stk *b, unsigned int n, int fst);
void	dscendba(t_stk *a, t_stk *b, int lst);
void	pushbyblockba(t_stk *a, t_stk *b, unsigned int n);
void	ascendab(t_stk *a, t_stk *b, unsigned int n, int fst);
void	dscendab(t_stk *a, t_stk *b, int lst);
void	pushbyblockab(t_stk *a, t_stk *b, unsigned int n);
void	sortbymerge(t_stk *a, t_stk *b);
char	aissorted(t_stk *a);
char	bissorted(t_stk *b);
void	printstk(t_stk *stk);
void	timsort(t_stk *a);
void	bmrgtimsort(t_stk *a);
int		*simplify_list(int size, int *tab);
void	triradix(t_stk *a, t_stk *b);
t_list	*gol(t_stk *stk);
void	*identity(void *nul);
void	lstdel_last(t_list **lst);
void	optriradix(t_stk *a, t_stk *b);
#endif
