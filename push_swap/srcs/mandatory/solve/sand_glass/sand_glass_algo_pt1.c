/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand_glass_algo_pt1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:24 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/23 03:20:29 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sand_glass(t_deque **deque_a, t_deque **deque_b)
{
	a2b(deque_a, deque_b);
	b2a(deque_a, deque_b);
}

int	ra_is_better(t_deque *deque_a, int _pivot)
{
	t_deque	*tail;

	tail = deque_a->tail;
	while (tail)
	{
		if (tail->index <= _pivot)
			break ;
		tail = tail->previous;
	}
	if (tail->loc <= tail->head->loc / 2)
		return (TRUE);
	return (FALSE);
}

void	a2b(t_deque **deque_a, t_deque **deque_b)
{
	int	pivot_and_size[2];
	int	idx;

	pivot_and_size[0] = deque_size(*deque_a);
	pivot_and_size[1] = (pivot_and_size[0] / 100) * 5 + 7;
	idx = 0;
	while (pivot_and_size[0])
		perform_sand_glass(pivot_and_size, &idx, deque_a, deque_b);
}

void	perform_sand_glass(int *info, int *idx, \
							t_deque **deque_a, t_deque **deque_b)
{
	int	tail_idx;

	tail_idx = (*deque_a)->tail->index;
	if (tail_idx <= *idx)
	{
		pb(deque_a, deque_b);
		info[0] = info[0] - 1;
		*idx = *idx + 1;
	}
	else if (tail_idx > *idx && tail_idx <= *idx + info[1])
	{
		pb(deque_a, deque_b);
		rb(deque_b, PERFORM);
		info[0] = info[0] - 1;
		*idx = *idx + 1;
	}
	else if (tail_idx > *idx + info[1])
		avoid_worst_case(deque_a, deque_b, *idx, info[1]);
}

void	avoid_worst_case(t_deque **deque_a, t_deque **deque_b, \
						int idx, int pivot)
{
	allocate_loc(*deque_a, *deque_b);
	if (ra_is_better(*deque_a, idx + pivot) == TRUE)
		ra(deque_a, PERFORM);
	else
		rra(deque_a, PERFORM);
}
