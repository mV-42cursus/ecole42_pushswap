/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mng_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:56 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:16 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deque_memory_mng(t_deque *deque)
{
	t_deque	*ptr;

	if (deque)
	{
		ptr = deque->head;
		deque = deque->head;
	}
	while (deque)
	{
		ptr = deque;
		deque = deque->next;
		free(ptr);
	}
	deque = NULL;
}

void	free_record(t_deque *deque_a, t_deque *deque_b)
{
	free_record_a(deque_a);
	free_record_b(deque_a);
	free_move(deque_a);
	free_greedy(deque_a);
	free_record_a(deque_b);
	free_record_b(deque_b);
	free_move(deque_b);
	free_greedy(deque_b);
}

void	free_record_a(t_deque *deque)
{
	t_record	*ptr;

	ptr = NULL;
	while (deque)
	{
		if (deque->record_a)
		{
			while (deque->record_a)
			{
				ptr = deque->record_a->next;
				free(deque->record_a);
				deque->record_a = ptr;
			}
		}
		deque = deque->next;
	}
}

void	free_record_b(t_deque *deque)
{
	t_record	*ptr;

	ptr = NULL;
	while (deque)
	{
		if (deque->record_b)
		{
			while (deque->record_b)
			{
				ptr = deque->record_b->next;
				free(deque->record_b);
				deque->record_b = ptr;
			}
		}
		deque = deque->next;
	}
}
