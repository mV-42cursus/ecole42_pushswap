/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_pt1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:45 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:18 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*deque_pop_front(t_deque **deque)
{
	t_deque	*node;
	t_deque	*new_head;

	node = NULL;
	new_head = NULL;
	if (*deque)
	{
		node = *deque;
		node->head = NULL;
		node->tail = NULL;
		new_head = node->next;
		if (new_head)
			new_head->previous = NULL;
		node->next = NULL;
		*deque = new_head;
		deque_head_tail(*deque);
	}
	return (node);
}

void	deque_push_front(t_deque **deque, t_deque *new)
{
	if (new == NULL)
		return ;
	node_add_front(deque, new);
	deque_head_tail(*deque);
}

t_deque	*deque_pop_back(t_deque **deque)
{
	t_deque	*node;
	t_deque	*new_tail;

	node = NULL;
	new_tail = NULL;
	if (*deque)
	{
		node = (*deque)->tail;
		new_tail = node->previous;
		if (new_tail)
			new_tail->next = NULL;
		else
			*deque = NULL;
		node->previous = NULL;
		deque_head_tail(*deque);
	}
	return (node);
}

void	deque_push_back(t_deque **deque, t_deque *new)
{
	if (new == NULL)
		return ;
	node_add_back(deque, new);
	deque_head_tail(*deque);
}
