/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_b_to_a_pt4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:37 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:02 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_arr_size(t_deque *deque_a, int flag)
{
	int	size;

	size = 0;
	if (flag == CAN_OPTIMIZE)
		size = find_best_case(deque_a);
	else
		size = find_original_case(deque_a);
	return (size);
}

int	find_best_case(t_deque *deque_a)
{
	int	size_a;
	int	size_b;
	int	size_move;
	int	optimized_size;
	int	remaining_size;

	size_a = record_size(deque_a->record_a);
	size_b = record_size(deque_a->record_b);
	size_move = record_size(deque_a->record_move);
	optimized_size = 0;
	if (size_a >= size_b)
	{
		optimized_size = size_b;
		remaining_size = size_a - size_b;
	}
	else
	{
		optimized_size = size_a;
		remaining_size = size_b - size_a;
	}
	return (optimized_size + remaining_size + size_move);
}

int	find_original_case(t_deque *deque_a)
{
	int	size_a;
	int	size_b;
	int	size_move;

	size_a = record_size(deque_a->record_a);
	size_b = record_size(deque_a->record_b);
	size_move = record_size(deque_a->record_move);
	return (size_a + size_b + size_move);
}

int	*arr_init(int *arr, int size, int flag, t_deque *deque_a)
{
	int	size_a;
	int	size_b;

	size_a = record_size(deque_a->record_a);
	size_b = record_size(deque_a->record_b);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	if (flag == CAN_OPTIMIZE)
	{
		if (size_a > size_b)
			optimize1(size_a, size_b, deque_a, arr);
		else
			optimize2(size_a, size_b, deque_a, arr);
	}
	else
		do_not_optimize(size_a, size_b, deque_a, arr);
	return (arr);
}

void	optimize1(int size_a, int size_b, t_deque *deque_a, int *arr)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	if (size_a > size_b)
	{
		min = size_b;
		while (i < min)
		{
			if (deque_a->record_a->operation[0] == RA)
				arr[i] = RR;
			else
				arr[i] = RRR;
			i++;
		}
		while (i < size_a)
			arr[i++] = deque_a->record_a->operation[0];
	}
	if (deque_a->record_move)
		arr[i] = deque_a->record_move->operation[0];
}
