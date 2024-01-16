/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:16 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:41 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_range(long res, char c, long sign)
{
	if (sign == -1)
	{
		if (res < 214748364 && (c >= '0' && c <= '9'))
			return (1);
		else if (res == 214748364 && (c >= '0' && c <= '8'))
			return (1);
		else if (res == 214748364 && (c == '9'))
			return (0);
		else if (res >= 214748365 && (c >= '0' && c <= '9'))
			return (0);
		else if (res == 2147483648 && (c >= '0' && c <= '9'))
			return (0);
	}
	else
	{
		if (res < 214748364 && (c >= '0' && c <= '9'))
			return (1);
		else if (res == 214748364 && (c >= '0' && c <= '7'))
			return (1);
		else if (res == 214748364 && (c == '8' || c == '9'))
			return (0);
		else if (res >= 214748365 && (c >= '0' && c <= '9'))
			return (0);
	}
	return (1);
}

int	is_non_numeric(char *av[])
{
	int	i;
	int	_i;

	i = 0;
	while (av[++i])
	{
		_i = -1;
		while (av[i][++_i])
		{
			if (!((av[i][_i] <= '9' && av[i][_i] >= '0') || av[i][_i] == ' '
				|| av[i][_i] == '+' || av[i][_i] == '-'))
				return (1);
		}
	}
	return (0);
}

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= 'A' && c <= 'Z')
		return (0);
	return (1);
}
