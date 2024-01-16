/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:00 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:35 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa(t_deque **deque_a)
{
	t_deque	*node1;
	t_deque	*node2;
	int		size;

	size = 0;
	if (*deque_a)
		size = deque_size(*deque_a);
	else
		size = 0;
	if (size == EMPTY || size == ONE)
		return (-1);
	node1 = deque_pop_back(deque_a);
	node2 = deque_pop_back(deque_a);
	deque_push_back(deque_a, node1);
	deque_push_back(deque_a, node2);
	deque_head_tail(*deque_a);
	return (1);
}

int	sb(t_deque **deque_b)
{
	t_deque	*node1;
	t_deque	*node2;
	int		size;

	if (*deque_b)
		size = deque_size(*deque_b);
	else
		size = 0;
	if (size == EMPTY || size == ONE)
		return (-2);
	node1 = deque_pop_back(deque_b);
	node2 = deque_pop_back(deque_b);
	deque_push_back(deque_b, node1);
	deque_push_back(deque_b, node2);
	deque_head_tail(*deque_b);
	return (2);
}

int	ss(t_deque **deque_a, t_deque **deque_b)
{
	sa(deque_a);
	sb(deque_b);
	return (3);
}
