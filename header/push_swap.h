/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:14 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/19 21:33:21 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

struct					s_stk
{
	t_list	*frst;
	t_list	*last;
};
typedef struct s_stk	t_stk;

char	swpstk(t_stk *stk);
char	pshstk(t_stk *A, t_stk *B);
#endif
