/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:08:02 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/20 17:03:06 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	ss(t_stk *a, t_stk *b)
{
	return (swpstk(a) | swpstk(b));
}

char	rr(t_stk *a, t_stk *b)
{
	return (rotstk(a) | rotstk(b));
}

char	rrr(t_stk *a, t_stk *b)
{
	return (rrtstk(a) | rrtstk(b));
}

char	op(t_stk *a, t_stk *b, char *str)
{
	if (!ft_strncmp(str, "sa", 4) || !ft_strncmp(str, "sa\n", 4))
		return (swpstk(a));
	else if (!ft_strncmp(str, "sb", 4) || !ft_strncmp(str, "sb\n", 4))
		return (swpstk(b));
	else if (!ft_strncmp(str, "ss", 4) || !ft_strncmp(str, "ss\n", 4))
		return (ss(a, b));
	else if (!ft_strncmp(str, "pa", 4) || !ft_strncmp(str, "pa\n", 4))
		return (pshstk(b, a));
	else if (!ft_strncmp(str, "pb", 4) || !ft_strncmp(str, "pb\n", 4))
		return (pshstk(a, b));
	else if (!ft_strncmp(str, "ra", 4) || !ft_strncmp(str, "ra\n", 4))
		return (rotstk(a));
	else if (!ft_strncmp(str, "rb", 4) || !ft_strncmp(str, "rb\n", 4))
		return (rotstk(b));
	else if (!ft_strncmp(str, "rr", 4) || !ft_strncmp(str, "rr\n", 4))
		return (rr(a, b));
	else if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rra\n", 4))
		return (rrtstk(a));
	else if (!ft_strncmp(str, "rrb", 4) || !ft_strncmp(str, "rrb\n", 4))
		return (rrtstk(b));
	else if (!ft_strncmp(str, "rrr", 4) || !ft_strncmp(str, "rrr\n", 4))
		return (rrr(a, b));
	else
		return (-1);
}
