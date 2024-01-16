/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:05 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:29 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra(t_deque **deque_a)
{
	t_deque	*node;
	int		size_a;

	if (*deque_a)
		size_a = deque_size(*deque_a);
	else
		size_a = 0;
	if (size_a == EMPTY || size_a == ONE)
		return (-9);
	node = deque_pop_front(deque_a);
	deque_push_back(deque_a, node);
	deque_head_tail(*deque_a);
	return (9);
}

int	rrb(t_deque **deque_b)
{
	t_deque	*node;
	int		size_b;

	if (*deque_b)
		size_b = deque_size(*deque_b);
	else
		size_b = 0;
	if (size_b == EMPTY || size_b == ONE)
		return (-10);
	node = deque_pop_front(deque_b);
	deque_push_back(deque_b, node);
	deque_head_tail(*deque_b);
	return (10);
}

int	rrr(t_deque **deque_a, t_deque **deque_b)
{
	rra(deque_a);
	rrb(deque_b);
	return (11);
}
