/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_b_to_a_pt3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:31:35 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 02:47:00 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort2(int **arr, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		if (arr[0][i] > arr[0][i + 1])
		{
			temp = arr[0][i];
			arr[0][i] = arr[0][i + 1];
			arr[0][i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	find_down(int *arr, int size, int tail_b_integer)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == tail_b_integer)
			break ;
		i++;
	}
	if (i == size - 1)
		return (arr[0]);
	return (arr[i + 1]);
}

int	find_up(int *arr, int size, int tail_b_integer)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == tail_b_integer)
			break ;
		i++;
	}
	if (i == 0)
		return (arr[size - 1]);
	return (arr[i - 1]);
}

void	optimize_record(t_deque *deque)
{
	int		*arr;
	int		size;
	int		not_best_case;

	arr = NULL;
	size = 0;
	not_best_case = 0;
	if (deque == NULL)
		return ;
	while (deque)
	{
		not_best_case = is_not_optimized(deque);
		if (not_best_case == TRUE)
			size = find_arr_size(deque, CAN_OPTIMIZE);
		else
			size = find_arr_size(deque, CANNOT_OPTIMIZE);
		arr = arr_init(arr, size, not_best_case, deque);
		create_record_greedy(arr, size, deque);
		deque = deque->next;
		free(arr);
	}
}

int	is_not_optimized(t_deque *deque_a)
{
	if (deque_a->record_a == NULL)
		return (0);
	if (deque_a->record_b == NULL)
		return (0);
	if (deque_a->record_a->operation[0] == RA && \
			deque_a->record_b->operation[0] == RB)
		return (1);
	if (deque_a->record_a->operation[0] == RRA && \
			deque_a->record_b->operation[0] == RRB)
		return (1);
	return (0);
}
