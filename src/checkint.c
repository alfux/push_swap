/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:47:27 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/21 17:28:43 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	isinbound(char *str)
{
	if (*str == '-' && ft_strncmp("-2147483648", str, 11) < 0)
		return (0);
	else if (*str == '+' && ft_strncmp("+2147483647", str, 11) < 0)
		return (0);
	else if (ft_strncmp("2147483647", str, 10) < 0)
		return (0);
	return (1);
}

static char	isinteger(char *str)
{
	int	i;

	if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		return (0);
	else if (*str == '-' || *str == '+')
		if (!ft_isdigit(*(str + 1)))
			return (0);
	i = 0;
	while (*(str + ++i))
		if (!ft_isdigit(*(str + i)))
			return (0);
	if (i > 10 + !ft_isdigit(*str))
		return (0);
	else if (i == 10 + !ft_isdigit(*str))
		return (isinbound(str));
	else
		return (1);
}

char	checkint(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (!isinteger(*(argv + i)))
			return (0);
	return (1);
}		
