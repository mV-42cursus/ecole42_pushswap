/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:02 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:27 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pa(t_deque **deque_a, t_deque **deque_b)
{
	t_deque	*node;
	int		size_b;

	if (*deque_b)
		size_b = deque_size(*deque_b);
	else
		size_b = 0;
	if (size_b == EMPTY)
		return (-4);
	node = deque_pop_back(deque_b);
	deque_push_back(deque_a, node);
	deque_head_tail(*deque_a);
	deque_head_tail(*deque_b);
	return (4);
}

int	pb(t_deque **deque_a, t_deque **deque_b)
{
	t_deque	*node;
	int		size_a;

	if (*deque_a)
		size_a = deque_size(*deque_a);
	else
		size_a = 0;
	if (size_a == EMPTY)
		return (-5);
	node = deque_pop_back(deque_a);
	deque_push_back(deque_b, node);
	deque_head_tail(*deque_a);
	deque_head_tail(*deque_b);
	return (5);
}

int	ra(t_deque **deque_a)
{
	t_deque	*node;
	int		size_a;

	if (*deque_a)
		size_a = deque_size(*deque_a);
	else
		size_a = 0;
	if (size_a == EMPTY || size_a == ONE)
		return (-6);
	node = deque_pop_back(deque_a);
	deque_push_front(deque_a, node);
	deque_head_tail(*deque_a);
	return (6);
}

int	rb(t_deque **deque_b)
{
	t_deque	*node;
	int		size_b;

	if (*deque_b)
		size_b = deque_size(*deque_b);
	else
		size_b = 0;
	if (size_b == EMPTY || size_b == ONE)
		return (-7);
	node = deque_pop_back(deque_b);
	deque_push_front(deque_b, node);
	deque_head_tail(*deque_b);
	return (7);
}

int	rr(t_deque **deque_a, t_deque **deque_b)
{
	ra(deque_a);
	rb(deque_b);
	return (8);
}
