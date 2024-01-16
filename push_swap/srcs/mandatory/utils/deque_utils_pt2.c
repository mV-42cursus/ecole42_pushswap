/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:46 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:20 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	deque_size(t_deque *deque)
{
	t_deque	*tail;
	int		size;

	tail = NULL;
	size = 0;
	if (deque)
		tail = deque->tail;
	while (tail)
	{
		size++;
		tail = tail->previous;
	}
	return (size);
}

void	record_add_back(t_record **node, int op)
{
	t_record	*p;
	t_record	*new;

	new = (t_record *)malloc(sizeof(t_record) * 1);
	if (new == NULL)
		return ;
	new->operation[0] = op;
	new->next = NULL;
	if (*node == NULL)
		(*node) = new;
	else
	{
		p = *node;
		while ((*node)->next)
			*node = (*node)->next;
		(*node)->next = new;
		*node = p;
	}
}
