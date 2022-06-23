/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:47:27 by afuchs            #+#    #+#             */
/*   Updated: 2022/06/23 22:07:31 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	isinbound(char *str, char c)
{
	if (c == '-' && ft_strncmp("2147483648", str, 10) < 0)
		return (0);
	else if (c == '+' && ft_strncmp("2147483647", str, 10) < 0)
		return (0);
	else if (c != '-' && ft_strncmp("2147483647", str, 10) < 0)
		return (0);
	return (1);
}

static int	realdigit(char *str, int *ei)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '0')
		i++;
	if (!*(str + i))
		return (0);
	while (*(str + i + n))
		n++;
	if (*str == '+' || *str == '-')
		n++;
	*ei = i;
	return (n);
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
	if (realdigit(str, &i) > 10 + !ft_isdigit(*str))
		return (0);
	else if (realdigit(str, &i) == 10 + !ft_isdigit(*str))
		return (isinbound(str + i, *str));
	else
		return (1);
}

char	freespl(char **spl)
{
	int	i;

	i = 0;
	while (*(spl + i))
		free(*(spl + i++));
	free(spl);
	return (2);
}

char	checkint(int argc, char **argv)
{
	int		i;
	char	ret;
	char	**spl;

	i = 0;
	ret = 1;
	if (argc == 2)
	{
		spl = ft_split(*(argv + 1), ' ');
		if (!*spl)
			return (freespl(spl));
		while (*(spl + i))
			if (!isinteger(*(spl + i++)))
				ret = 0;
		freespl(spl);
		return (ret);
	}
	while (++i < argc)
		if (!isinteger(*(argv + i)))
			return (0);
	return (1);
}		
