/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:37:16 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:47:19 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long long	nbr;
	int			res;

	nbr = (long long)nb;
	res = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		res = write(1, "-", 1);
		if (res == -1)
			return (-1);
	}
	if (nbr > 9)
	{
		res = ft_putnbr(nbr / 10);
		if (res == -1)
			return (-1);
	}
	res = ft_display_nbr(nbr % 10);
	if (res == -1)
		return (-1);
	return (1);
}
