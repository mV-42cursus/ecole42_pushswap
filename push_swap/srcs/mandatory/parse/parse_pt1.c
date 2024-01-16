/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:08 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:36 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int ac, char *av[], int **buffer, int *size)
{
	char	**candidate;
	int		i;

	i = -1;
	if (is_wrongly_delimited(av) || is_only_delimited(av))
		return (0);
	if (is_empty_string(ac, av))
		return (0);
	if (is_double_sign(av))
		return (0);
	if (is_non_numeric(av))
		return (0);
	candidate = ft_split_ps(av, ' ');
	if (is_overflow(candidate, &buffer, &size))
	{
		while (candidate[++i])
			free(candidate[i]);
		return (free(candidate), 0);
	}
	if (is_redundant(&buffer, &size))
		return (free(*buffer), 0);
	return (1);
}

int	ft_strlen2(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	is_wrongly_delimited(char *av[])
{
	int	i;
	int	k;

	i = 1;
	while (av[i])
	{
		k = -1;
		while (av[i][++k])
		{
			if ((av[i][k] >= '0' && av[i][k] <= '9')
			&& (!((av[i][k + 1] == ' ')
			|| av[i][k + 1] == '\0'
			|| (av[i][k + 1] >= '0'
			&& av[i][k + 1] <= '9'))))
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_only_delimited(char *av[])
{
	int	i;
	int	_i;

	i = 1;
	_i = 0;
	while (av[i])
	{
		_i = 0;
		while (av[i][_i])
		{
			if (av[i][_i] == ' ')
				_i++;
			else
				break ;
		}
		if (_i == ft_strlen2(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_redundant(int ***buffer, int **size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < **size)
	{
		k = i + 1;
		while (k < **size)
		{
			if (buffer[0][0][i] == buffer[0][0][k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
