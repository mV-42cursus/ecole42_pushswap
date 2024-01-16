/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_b_to_a_pt5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:39 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:04 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize2(int size_a, int size_b, t_deque *deque_a, int *arr)
{
	int	min;
	int	i;

	min = size_a;
	i = 0;
	while (i < min)
	{
		if (deque_a->record_a->operation[0] == RA)
			arr[i] = RR;
		else
			arr[i] = RRR;
		i++;
	}
	while (i < size_b)
		arr[i++] = deque_a->record_b->operation[0];
	if (deque_a->record_move)
		arr[i] = deque_a->record_move->operation[0];
}

void	do_not_optimize(int size_a, int size_b, t_deque *deque_a, int *arr)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (i < size_a)
	{
		arr[k] = deque_a->record_a->operation[0];
		k++;
		i++;
	}
	i = 0;
	while (i < size_b)
	{
		arr[k] = deque_a->record_b->operation[0];
		i++;
		k++;
	}
	if (deque_a->record_move)
		arr[k] = deque_a->record_move->operation[0];
}

void	create_record_greedy(int *arr, int size, t_deque *deque_a)
{
	int	i;

	i = 0;
	while (i < size)
		record_add_back(&(deque_a->record_greedy), arr[i++]);
}
