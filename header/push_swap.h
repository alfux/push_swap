/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/16 22:18:43 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

struct					s_stk
{
	t_list	*frst;
	t_list	*last;
	int		size;
	char	name;
	int		lrg;
	int		sml;
	t_list	**output;
};
typedef struct s_stk	t_stk;

void			swpstk(t_stk *stk);
void			pshstk(t_stk *A, t_stk *B);
void			rotstk(t_stk *stk);
void			rrtstk(t_stk *stk);
char			checkint(int argc, char **argv);
char			aissorted(t_stk *a);
char			bissorted(t_stk *b);
void			printstk(t_stk *stk);
void			timsort(t_stk *a);
void			bmrgtimsort(t_stk *a);
void			lstdel_last(t_list **lst);
int				swtelem(t_stk *a, t_list *elem);
void			smartrot(t_stk *stk, int moves);
void			quicksortab(t_stk *a, t_stk *b, int blcksz);
void			quicksortba(t_stk *a, t_stk *b, int blcksz);
unsigned int	ft_abs(int n);
char			ablckissorted(t_stk *a, int blcksz);
char			bblckissorted(t_stk *b, int blcksz);
void			aswp(t_stk *a);
void			bswp(t_stk *b);
void			clnoutput(t_list **output);
void			addoutput(t_list **output, char *str);
char			tryout(t_list *output, t_stk *a, t_stk *b);
void			clrstk(t_stk *stk);
t_stk			*getstk(int size, int *tab);
#endif
