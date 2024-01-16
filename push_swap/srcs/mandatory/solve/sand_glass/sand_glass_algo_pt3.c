/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand_glass_algo_pt3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:28 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:15 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*find_max2(t_deque **deque_b)
{
	t_deque	*dup;
	int		max;

	dup = *deque_b;
	max = dup->integer;
	while (dup)
	{
		if (max < dup->integer)
			max = dup->integer;
		dup = dup->next;
	}
	dup = *deque_b;
	while (dup)
	{
		if (dup->integer == max)
			break ;
		dup = dup->next;
	}
	return (dup);
}
