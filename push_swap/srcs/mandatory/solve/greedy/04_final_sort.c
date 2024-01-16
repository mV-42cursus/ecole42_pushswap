/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_final_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:41 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:07 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_deque **deque_a, t_deque **deque_b)
{
	int	min;
	int	loc;

	min = 0;
	loc = 0;
	allocate_loc(*deque_a, *deque_b);
	min = find_min(*deque_a);
	loc = find_min_loc(*deque_a, min);
	if (loc <= (*deque_a)->head->loc / 2)
		push_down(deque_a, min);
	else
		push_up(deque_a, min);
}

int	find_min(t_deque *deque_a)
{
	int	min;

	min = deque_a->integer;
	while (deque_a)
	{
		if (min > deque_a->integer)
			min = deque_a->integer;
		deque_a = deque_a->next;
	}
	return (min);
}

int	find_min_loc(t_deque *deque_a, int min)
{
	while (deque_a)
	{
		if (deque_a->integer == min)
			break ;
		deque_a = deque_a->next;
	}
	return (deque_a->loc);
}

void	push_down(t_deque **deque_a, int min)
{
	while (1)
	{
		if ((*deque_a)->tail->integer == min)
			break ;
		ra(deque_a, PERFORM);
	}
}

void	push_up(t_deque **deque_a, int min)
{
	while (1)
	{
		if ((*deque_a)->tail->integer == min)
			break ;
		rra(deque_a, PERFORM);
	}
}
