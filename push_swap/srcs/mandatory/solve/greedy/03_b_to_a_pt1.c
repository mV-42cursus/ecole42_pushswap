/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_b_to_a_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:31 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:46:54 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_deque **deque_a, t_deque **deque_b)
{
	while (1)
	{
		initialize_cost(*deque_a, *deque_b);
		allocate_loc(*deque_a, *deque_b);
		if (deque_size(*deque_b) == EMPTY)
			break ;
		toss_one_b2a(deque_a, deque_b);
	}
}

void	toss_one_b2a(t_deque **deque_a, t_deque **deque_b)
{
	t_deque	*tail_b;

	tail_b = (*deque_b)->tail;
	while (1)
	{
		if (is_all_calculated((*deque_b)->tail) == TRUE)
			break ;
		record_a2((*deque_a)->tail, tail_b);
		record_b2(tail_b);
		record_move(tail_b, B);
		calculate_cost(tail_b);
		tail_b = tail_b->previous;
	}
	optimize_record(*deque_b);
	toss_node(deque_a, deque_b, B);
	free_record(*deque_a, *deque_b);
}

void	record_a2(t_deque *tail_a, t_deque *tail_b)
{
	int	size;
	int	down;
	int	*arr;
	int	down_loc;

	size = 0;
	arr = arr_init2(tail_a, tail_b->integer, &size);
	bubble_sort2(&arr, size);
	down = find_down(arr, size, tail_b->integer);
	down_loc = find_val_loc(tail_a, down);
	if (down_loc <= tail_a->head->loc / 2)
		record_ra(down_loc, arr, tail_b);
	else
		record_rra(down_loc, arr, tail_a, tail_b);
}

void	record_ra(int down_loc, int *arr, t_deque *tail_b)
{
	while (down_loc != 0)
	{
		record_add_back(&(tail_b->record_a), RA);
		down_loc--;
	}
	free(arr);
}

void	record_rra(int down_loc, int *arr, t_deque *tail_a, t_deque *tail_b)
{
	if (down_loc == tail_a->head->loc)
	{
		record_add_back(&(tail_b->record_a), RRA);
		free (arr);
		return ;
	}
	while (down_loc != tail_a->head->loc + 1)
	{
		record_add_back(&(tail_b->record_a), RRA);
		down_loc++;
	}
	free(arr);
}
