/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 03:24:49 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/14 18:53:56 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((-1) * n);
	return (n);
}
