/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pt2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:47:32 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:40 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_deque **deque_a, t_deque **deque_b)
{
	t_deque	*tail;

	if (*deque_a)
		tail = (*deque_a)->tail;
	if (deque_size(*deque_b) != EMPTY)
		return (0);
	if (deque_size(*deque_a) == 1)
		return (1);
	while (tail->previous)
	{
		if (tail->integer > tail->previous->integer)
			return (0);
		tail = tail->previous;
	}
	return (1);
}

void	perform_bonus_op(t_deque **deque_a, t_deque **deque_b, int operation)
{
	if (operation == SA)
		sa(deque_a);
	if (operation == SB)
		sb(deque_a);
	if (operation == SS)
		ss(deque_a, deque_b);
	if (operation == PA)
		pa(deque_a, deque_b);
	if (operation == PB)
		pb(deque_a, deque_b);
	if (operation == RA)
		ra(deque_a);
	if (operation == RB)
		rb(deque_b);
	if (operation == RR)
		rr(deque_a, deque_b);
	if (operation == RRA)
		rra(deque_a);
	if (operation == RRB)
		rrb(deque_b);
	if (operation == RRR)
		rrr(deque_a, deque_b);
}

void	display_result_bonus(t_deque **deque_a, t_deque **deque_b)
{
	if (is_sorted(deque_a, deque_b) == TRUE)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
