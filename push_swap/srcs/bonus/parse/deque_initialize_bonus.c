/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_initialize_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:43 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:53 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_deque	*deque_init(t_deque *node, int *buffer, int i, int size)
{
	t_deque	*new;

	node = node_init(node);
	node->integer = buffer[i++];
	while (i < size)
	{
		new = node_init(new);
		new->integer = buffer[i++];
		node_add_front(&node, new);
	}
	deque_head_tail(node);
	return (node);
}

t_deque	*node_init(t_deque *node)
{
	node = (t_deque *)malloc(sizeof(t_deque) * 1);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->previous = NULL;
	node->head = NULL;
	node->tail = NULL;
	node->record_a = NULL;
	node->record_b = NULL;
	node->record_move = NULL;
	node->record_greedy = NULL;
	return (node);
}

void	node_add_front(t_deque **node, t_deque *new)
{
	t_deque	*p;

	if (new == NULL)
		return ;
	if (*node == NULL)
		(*node) = new;
	else
	{
		p = *node;
		p->previous = new;
		new->next = p;
		new->previous = NULL;
		*node = new;
	}
}

void	node_add_back(t_deque **node, t_deque *new)
{
	t_deque	*p;

	if (new == NULL)
		return ;
	if (*node == NULL)
		(*node) = new;
	else
	{
		p = *node;
		while ((*node)->next)
			*node = (*node)->next;
		(*node)->next = new;
		new->next = NULL;
		new->previous = *node;
		*node = p;
	}
}

void	deque_head_tail(t_deque *deque)
{
	t_deque	*p;
	t_deque	*head;
	t_deque	*tail;

	p = NULL;
	if (deque)
	{
		p = deque;
		head = deque;
		while (deque->next)
			deque = deque->next;
		tail = deque;
	}
	deque = p;
	while (deque)
	{
		deque->head = head;
		deque->tail = tail;
		deque = deque->next;
	}
}
