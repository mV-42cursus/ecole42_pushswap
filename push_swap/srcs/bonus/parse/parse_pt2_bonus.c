/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:10 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:22 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_empty_string(int ac, char **av)
{
	int	rotation;

	rotation = 1;
	while (rotation < ac)
	{
		if (av[rotation][0] == '\0')
			return (1);
		rotation++;
	}
	return (0);
}

int	is_double_sign(char **av)
{
	int	i;
	int	_i;

	_i = 0;
	while (av[++_i])
	{
		i = 0;
		while (av[_i][i])
		{
			if (is_double(av, _i, i) == TRUE)
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_double(char **av, int _i, int i)
{
	if (av[_i][i] == '+' && (av[_i][i + 1] == '+'
		|| av[_i][i + 1] == ' ' || av[_i][i + 1] == '\0'))
		return (1);
	else if (av[_i][i] == '-' && (av[_i][i + 1] == '-'
		|| av[_i][i + 1] == ' ' || av[_i][i + 1] == '\0'))
		return (1);
	else if (av[_i][i] == '+' && (av[_i][i + 1] == '-'
		|| av[_i][i + 1] == ' ' || av[_i][i + 1] == '\0'))
		return (1);
	else if (av[_i][i] == '-' && (av[_i][i + 1] == '+'
		|| av[_i][i + 1] == ' ' || av[_i][i + 1] == '\0'))
		return (1);
	return (0);
}

int	is_overflow(char **candidate, int ***buffer, int **size)
{
	int	i;
	int	overflow;

	i = -1;
	overflow = 0;
	while (candidate[**size] != NULL)
	{
		push_swap_atoi(candidate[**size], &overflow);
		if (overflow == 1)
			return (1);
		**size = **size + 1;
	}
	buffer[0][0] = (int *)malloc(sizeof(int) * (**size));
	while (candidate[++i] != NULL)
	{
		buffer[0][0][i] = push_swap_atoi(candidate[i], &overflow);
		free(candidate[i]);
	}
	free(candidate);
	return (0);
}

int	push_swap_atoi(char *str, int *overflow)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (is_int_range(res, *str, sign) == 0)
		{
			*overflow = 1;
			return (0);
		}
		else
			res = (10 * res) + (*str - '0');
		str++;
	}
	while (!is_alpha(*str))
		return (0);
	return ((sign) * res);
}
