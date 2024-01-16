/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_pt1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:35 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:26 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_loc(t_deque *deque_a, t_deque *deque_b)
{
	t_deque	*begin;
	int		i;

	i = 0;
	if (deque_a)
	{
		begin = deque_a->tail;
		while (deque_a->tail)
		{
			deque_a->tail->loc = i++;
			deque_a->tail = deque_a->tail->previous;
		}
		deque_a->tail = begin;
	}
	i = 0;
	if (deque_b)
	{
		begin = deque_b->tail;
		while (deque_b->tail)
		{
			deque_b->tail->loc = i++;
			deque_b->tail = deque_b->tail->previous;
		}
		deque_b->tail = begin;
	}
}

void	initialize_cost(t_deque *deque_a, t_deque *deque_b)
{
	t_deque	*tail_a;
	t_deque	*tail_b;

	if (deque_a)
		tail_a = deque_a->tail;
	if (deque_b)
		tail_b = deque_b->tail;
	if (deque_a)
	{
		while (tail_a)
		{
			tail_a->cost = 0;
			tail_a = tail_a->previous;
		}
	}
	if (deque_b)
	{
		while (tail_b)
		{
			tail_b->cost = 0;
			tail_b = tail_b->previous;
		}
	}
}

int	is_all_calculated(t_deque *deque)
{
	t_deque	*tail;

	tail = deque->tail;
	while (tail)
	{
		if (tail->cost == 0)
			return (FALSE);
		tail = tail->previous;
	}
	return (TRUE);
}

int	record_size(t_record *record)
{
	int		size;

	size = 0;
	if (record == NULL)
		return (0);
	while (record)
	{
		size++;
		record = record->next;
	}
	return (size);
}

void	bubble_sort(int **arr, int size)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	while (i < size - 1)
	{
		if (arr[0][i] < arr[0][i + 1])
		{
			temp = arr[0][i];
			arr[0][i] = arr[0][i + 1];
			arr[0][i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
